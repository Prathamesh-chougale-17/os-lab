#include <bits/stdc++.h>
using namespace std;

struct Process
{
	int pid;
	int bt;
	int art;
};

void findWaitingTime(Process proc[], int n, int wt[])
{
	int rt[n];
	for (int i = 0; i < n; i++)
		rt[i] = proc[i].bt;

	int complete = 0, t = 0, minm = INT_MAX;
	int shortest = 0, finish_time;
	bool check = false;

	while (complete != n)
	{
		for (int j = 0; j < n; j++)
		{
			if ((proc[j].art <= t) && (rt[j] < minm) && rt[j] > 0)
			{
				minm = rt[j];
				shortest = j;
				check = true;
			}
		}

		if (check == false)
		{
			t++;
			continue;
		}

		rt[shortest]--;
		minm = rt[shortest];

		if (minm == 0)
			minm = INT_MAX;

		if (rt[shortest] == 0)
		{
			complete++;
			check = false;
			finish_time = t + 1;
			wt[shortest] = finish_time - proc[shortest].bt - proc[shortest].art;

			if (wt[shortest] < 0)
				wt[shortest] = 0;
		}

		t++;
	}
}

void findTurnAroundTime(Process proc[], int n, int wt[], int tat[])
{
	for (int i = 0; i < n; i++)
		tat[i] = proc[i].bt + wt[i];
}

void findavgTime(Process proc[], int n)
{
	int wt[n], tat[n], total_wt = 0, total_tat = 0;
	findWaitingTime(proc, n, wt);
	findTurnAroundTime(proc, n, wt, tat);

	cout << " P\t\t"
		 << "BT\t\t"
		 << "WT\t\t"
		 << "TAT\t\t\n";

	for (int i = 0; i < n; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		cout << " " << proc[i].pid << "\t\t"
			 << proc[i].bt << "\t\t " << wt[i]
			 << "\t\t " << tat[i] << endl;
	}

	cout << "\nAverage waiting time = " << (float)total_wt / (float)n;
	cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}

int main()
{
	// Process proc[] = {{1, 6, 2}, {2, 2, 5}, {3, 8, 1}, {4, 3, 0}, {5, 4, 4}};
	int n{0};
	cout << "Enter the number of Process you want: " << endl;
	cin >> n;
	cout << "Enter the values Accordingly" << endl;
	Process proc[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the Process ID " << i + 1 << " : ";
		cin >> proc[i].pid;
		cout << "Enter the Burst time " << i + 1 << " : ";
		cin >> proc[i].bt;
		cout << "Enter the Arrival time " << i + 1 << " : ";
		cin >> proc[i].art;
	}
	// cin>>
	int x = sizeof(proc) / sizeof(proc[0]);

	findavgTime(proc, x);
	return 0;
}
