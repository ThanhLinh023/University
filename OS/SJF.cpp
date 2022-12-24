#include<iostream>
using namespace std;

struct Process
{
    int name, arrT, burT, resT, tat , wt, start, finish;
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
    int n;
    Process p[100];
    cout << "Enter number of processes: "; cin >> n;
    for (int i = 0; i < n; i++)
    {
        p[i].name = i + 1;
        cout << "Enter Arrival Time & Burst Time: P" << p[i].name << " ";
        cin  >> p[i].arrT >> p[i].burT;
    }
	sortProcess(p, n);
    int done[n];
	for (int i = 0; i < n; i++) done[i] = 0;

	float timeNow = p[0].arrT + p[0].burT;
	p[0].finish = timeNow;
	p[0].tat = p[0].finish - p[0].arrT;
	p[0].wt = p[0].tat - p[0].burT;
	p[0].resT = p[0].wt;

	done[0] = 1;
	for (int i = 1; i < n; i++)
    {
		float shortestBurT = 1e9;
		int index = -1;
		for (int j = 1; j < n; j++)
        {
			if (!done[j] && timeNow >= p[j].arrT && shortestBurT > p[j].burT)
            {
				shortestBurT = p[j].burT;
				index = j;
			}
		}
		if (index == -1)
        {
			float shortestArrT = 1e9;
			for (int j = 0; j < n; j++)
            {
				if (!done[j] && shortestArrT > p[j].arrT && p[j].arrT > timeNow) 
                {
					shortestArrT = p[j].arrT;
					index = j;
				}
            }
			if (index == -1) break;
		    timeNow = shortestArrT;
		}
		timeNow += p[index].burT;
		p[index].finish = timeNow;
		p[index].tat = p[index].finish - p[index].arrT;
		p[index].wt = p[index].tat - p[index].burT;
		p[index].resT = p[index].wt;
		done[index] = 1;
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