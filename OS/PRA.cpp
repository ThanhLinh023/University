#include<iostream>
using namespace std;

void printAnswer(int seq[100], int table[100][100], char fault[100], int n, int frame)
{
    system("cls");
    int count = 0;
    cout << "-- Page Replacement Algorithm --\n";
    for (int i = 0; i < n; i++)
    {
        cout << seq[i] << "\t ";
    }
    cout << endl;
    for (int i = 0; i < frame; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (table[i][j] != -1)
            {
                cout << table[i][j] << "\t ";
            }
            else cout << "\t ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        cout << fault[i] << "\t ";
        if (fault[i] == '*') count++;
    }
    cout << "\nNumber of page faults: " << count;
}

int inReferenced(int table[100][100], int frame, int i, int page)
{
    for (int j = 0; j < frame; j++)
    {
        if (table[j][i] == page || table[j][i] == -1) return j;
    }
    return -1;
}

void FIFO(int seq[100], int table[100][100], char fault[100], int n, int frame)
{
    int first = 0;
    table[0][0] = seq[0];
    fault[0] = '*';
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < frame; j++)
        {
            table[j][i] = table[j][i - 1];
        }
        int index = inReferenced(table, frame, i, seq[i]); 
        if (index != -1)
        {
            if (table[index][i] == -1)
            {
                table[index][i] = seq[i];
                fault[i] = '*';
            }
            else fault[i] = ' ';
        }
        else
        {
            fault[i] = '*';
            table[first][i] = seq[i];
            first = (first + 1) % frame;
        }
    }
}

void OPT(int seq[100], int table[100][100], char fault[100], int n, int frame)
{
    int next[100], k;
    table[0][0] = seq[0];
    fault[0] = '*';
    for (k = 1; k < n; k++)
    {
        if (seq[k] == seq[0]) break;
    }
    next[0] = k;
    for (int i = 1; i < n; i++)
    {
        int j;
        for (j = 0; j < frame; j++)
        {
            table[j][i] = table[j][i - 1];
        }
        int index = inReferenced(table, frame, i, seq[i]);
        if (index == -1)
        {
            int select = 0;
            for (j = 1; j < frame; j++)
            {
                if (next[select] < next[j]) select = j;
            }
            table[select][i] = seq[i];
            for (j = i + 1; j < n; j++)
            {
                if (seq[j] == seq[i]) break;
            }
            next[select] = j;
            fault[i] = '*';
        }
        else
        {
            if (table[index][i] == -1)
            {
                table[index][i] = seq[i];
                fault[i] = '*';
            }
            else fault[i] = ' ';
            j = i + 1;
            for (j = i + 1; j < n; j++)
            {
                if (seq[j] == seq[i]) break;
            }
            next[index] = j;
        }
    }
}

void LRU(int seq[100], int table[100][100], char fault[100], int n, int frame)
{
    int last[100];
    table[0][0] = seq[0];
	fault[0] = '*';
	last[0] = 0;
    for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < frame; j++)
        {
		    table[j][i] = table[j][i - 1];
        }
	    int index = inReferenced(table, frame, i, seq[i]);
		if (index == -1)
		{
			fault[i] = '*';
			int minReferenced = 0;
			for (int j = 1; j < frame; j++)
            {
				if (last[j] < last[minReferenced]) minReferenced = j;
            }
			last[minReferenced] = i;
			table[minReferenced][i] = seq[i];
		}
		else
		{
			if (table[index][i] == -1) 
            {
				table[index][i] = seq[i];
				fault[i] = '*';
			} else fault[i] = ' ';
			last[index] = i;
		}
	}
}

int main()
{
    int frame, algorithm, a[1000], n = 0, k;
    int table[100][100];
    char fault[100];
    int defaultSeq[12] = {2, 1, 5, 2, 1, 0, 8, 2, 0, 0, 7};
    cout << "-- Page Replacement Algorithm --\n";
    cout << "1. Default referenced sequence: 2 1 5 2 1 0 8 2 0 0 7\n";
    cout << "2. Manual input sequence\n";
    cout << "Choose one option: ";
    cin >> k;
    if (k == 2)
    {
        system("cls");
        cout << "Input sequence (-1 to stop input): ";
        while (1)
        {
            cin >> a[n];
            if (a[n] == -1) break;
            n++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                table[i][j] = -1;
            }
        }
    }
    else
    {
        n = 11;
        for (int i = 0; i < 11; i++)
        {
            a[i] = defaultSeq[i];
            for (int j = 0; j < 11; j++)
            {
                table[i][j] = -1;
            }
        }
    }
    system("cls");
    cout << "-- Page Replacement Algorithm --\n";
    cout << "Input page frame: "; cin >> frame;
    system("cls");
    cout << "-- Page Replacement Algorithm --\n";
    cout << "1. FIFO Algorithm\n";
    cout << "2. OPT Algorithm\n";
    cout << "3. LRU Algorithm\n";
    cout << "Choose one option: "; cin >> algorithm;
    if (algorithm == 1)
    {
        FIFO(a, table, fault, n, frame);
    }
    else if (algorithm == 2)
    {
        OPT(a, table, fault, n, frame);
    }
    else
    {
        LRU(a, table, fault, n, frame);
    }
    printAnswer(a, table, fault, n, frame);
    return 0;
}