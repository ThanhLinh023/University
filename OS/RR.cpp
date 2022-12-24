#include<iostream>
#include<queue>
using namespace std;

struct Process
{
    int name, arrT, burT, resT, tat , wt, start, finish;
    int remain;
	Process()
	{
		resT = tat = wt = finish = 0;
	}
};

void sortProcess(Process p[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (p[i].arrT > p[j].arrT)
			{
				Process temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
			else if (p[i].arrT == p[j].arrT && p[i].name > p[j].name)
			{
				Process temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}


int main()
{
    int n, Qt;
    Process p[100];
    cout << "Enter number of processes: "; cin >> n;
    for (int i = 0; i < n; i++)
    {
        p[i].name = i + 1;
        cout << "Enter Arrival Time & Burst Time: P" << p[i].name << " ";
        cin  >> p[i].arrT >> p[i].burT;
		p[i].remain = p[i].burT;
    }
    cout << "Enter quantum time: "; cin >> Qt;
    queue<Process> Q;

	sortProcess(p, n);
		
    float timeNow = 0;
	int done[n];
	for (int i = 0; i < n; i++) done[i] = 0;

	int num = 0;
	int temp = n;
	while (temp > 0)
	{	
		while (num < n)
        {
			if (done[num] == 0)
            {
				Q.push(p[num]);
				timeNow = p[num++].arrT;
				break;
			}
			num++;
		}
		while (!Q.empty())
        {
			int index = Q.front().name - 1;
			Q.pop();
			if (p[index].remain == p[index].burT)
            {
				p[index].resT = timeNow - p[index].arrT;	
			}

			int rTime = p[index].remain;
			if (rTime > Qt) 
			{
				rTime = Qt;
			}

			timeNow += rTime;
			p[index].remain -= rTime;

			while (num < n && p[num].arrT <= timeNow) 
            {
				Q.push(p[num]);
				num++;
			}

			if (p[index].remain == 0) 
			{
				p[index].finish = timeNow;
				p[index].tat = p[index].finish - p[index].arrT;
				p[index].wt = p[index].tat - p[index].burT;
				done[index] = 1;
				temp--;
			}	
			else Q.push(p[index]);	
		}

	}

    float totWt, totTat;
    cout << "ProcessName\tResponseTime\tWaitingTime\tTurnaroundTime\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << p[i].name << "\t\t" << p[i].resT << "\t\t" << p[i].wt << "\t\t" << p[i].tat << endl;
        totWt += p[i].wt;
        totTat += p[i].tat;
    }
    cout << "Average Waiting Time: " << totWt / n;
    cout << "\nAverage Turnaround Time: " << totTat / n;
    return 0;
}