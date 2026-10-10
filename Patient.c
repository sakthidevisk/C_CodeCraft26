
#include <stdio.h>

struct Patient
{
    int id;
    char name[50];
    int priority;
    char symptoms[100];
    char doctor[50];
    int bed;
    char status[30];
};

int main()
{
    struct Patient p[100], temp;
    int n, doctors, beds;
    int waiting = 0, treating = 0, discharged = 0;
    int doctorCount = 0, bedCount = 0;

    printf("Enter number of patients: ");
    scanf("%d", &n);

    if (n < 1 || n > 100)
    {
        printf("Invalid number of patients!\n");
        return 0;
    }

    printf("Enter available doctors: ");
    scanf("%d", &doctors);

    printf("Enter available beds: ");
    scanf("%d", &beds);

    
    for (int i = 0; i < n; i++)
    {
        printf("\nPatient %d\n", i + 1);

        printf("Patient ID: ");
        scanf("%d", &p[i].id);

        printf("Patient name: ");
        scanf("%s ", &p[i].name);

        printf("Priority (1-Low, 2-Medium, 3-High, 4-Critical): ");
        scanf("%d", &p[i].priority);

        if (p[i].priority < 1 || p[i].priority > 4)
        {
            printf("Invalid priority! Enter 1 to 4: ");
            scanf("%d", &p[i].priority);
        }

        printf("Symptoms: ");
        scanf(" %99[^\n]", p[i].symptoms);

        p[i].doctor[0] = '\0';
        p[i].bed = 0;
        p[i].status[0] = '\0';
    }

    
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].priority < p[j + 1].priority)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

   
    for (int i = 0; i < n; i++)
    {
        if (doctorCount < doctors)
        {
            doctorCount++;
            sprintf(p[i].doctor, "Doctor %d", doctorCount);
            strcpy(p[i].status, "Under Treatment");
            treating++;
        }
        else
        {
            strcpy(p[i].doctor, "Not Assigned");
            strcpy(p[i].status, "Waiting");
            waiting++;
        }

        if (bedCount < beds && doctorCount <= doctors &&
            p[i].status[0] == 'U')
        {
            bedCount++;
            p[i].bed = bedCount;
        }
    }

    
    printf("\n--- HOSPITAL EMERGENCY QUEUE ---\n");

    for (int i = 0; i < n; i++)
    {
        printf("\nID: %d | Name: %s\n", p[i].id, p[i].name);
        printf("Priority: %d\n", p[i].priority);
        printf("Symptoms: %s\n", p[i].symptoms);
        printf("Doctor: %s\n", p[i].doctor);

        if (p[i].bed == 0)
            printf("Bed: Not Assigned\n");
        else
            printf("Bed: %d\n", p[i].bed);

        printf("Status: %s\n", p[i].status);
    }

    printf("\n--- EMERGENCY SUMMARY ---\n");
    printf("Total patients: %d\n", n);
    printf("Waiting: %d\n", waiting);
    printf("Under treatment: %d\n", treating);
    printf("Doctors assigned: %d\n", doctorCount);
    printf("Beds assigned: %d\n", bedCount);

    return 0;
}
