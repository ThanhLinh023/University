#include<iostream>
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

int shortestRT(Process p[], int n, int time, int done[])
{
    int jobIndex = -1;
	float shortestTime = 1e9;
	for (int i = 0; i < n; i++)
    {
		if (!done[i] && p[i].arrT <= time && p[i].remain < shortestTime)
        {
			jobIndex = i;
			shortestTime = p[i].remain;
		}
	}
	return jobIndex;
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
		p[i].remain = p[i].burT;
    }
	sortProcess(p, n);
    float timeNow = p[0].arrT;
    int num = 1; 
	int temp = 0; 
	temp = n;
	int done[n];
	int preIndex = 0;
	for (int i = 0; i < n; i++) done[i] = 0;
	

	while (temp > 0)
	{
		if (p[preIndex].burT == p[preIndex].remain)
		{
			p[preIndex].resT = timeNow - p[preIndex].arrT;
		}

		if (num < n && timeNow + p[preIndex].remain >= p[num].arrT)
		{
			float rTime = timeNow + p[preIndex].remain  - p[num].arrT;
			timeNow = p[num].arrT;
			p[preIndex].remain = rTime;
			if (rTime == 0)
			{
				p[preIndex].finish = timeNow;
				p[preIndex].tat = p[preIndex].finish - p[preIndex].arrT;
				p[preIndex].wt = p[preIndex].tat - p[preIndex].burT;
				done[preIndex] = 1;
				temp--;
			}

			if (p[num].burT < rTime) 
			{
				preIndex = num;
			}
			num++;
		}
		else
		{
			int index = shortestRT(p, n, timeNow,done);
			if (num < n)
			{
				if (index == -1)
				{
					timeNow = p[num].arrT;
					preIndex = num;
					num++;
				}
				else
				{
					if (timeNow + p[index].remain < p[num].arrT)
					{
						if (p[index].burT == p[index].remain) 
						{
							p[index].resT = timeNow - p[index].arrT;
						}

						timeNow += p[index].remain;
						p[index].remain = 0;
						p[index].finish = timeNow;
						p[index].tat = p[index].finish - p[index].arrT;
						p[index].wt = p[index].tat - p[index].burT;
						done[index] = 1;
						temp--;
					}
					preIndex = index;
				}	
			}
			else
			{
				if (p[index].burT == p[index].remain) p[index].resT = timeNow - p[index].arrT;

				timeNow += p[index].remain;
				p[index].remain = 0;
				p[index].finish = timeNow;
				p[index].tat = p[index].finish - p[index].arrT;
				p[index].wt = p[index].tat - p[index].burT;
				done[index] = 1;
				preIndex = index;
				temp--;
			}
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