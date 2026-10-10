
#include <stdio.h>

struct Rescue
{
    int id;
    char location[50];
    int people;
    int level;
    char resources[50];
    char team[50];
    char status[30];
};

int main()
{
    struct Rescue r[100], temp;
    int n;

    printf("Enter number of rescue requests: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nRequest %d\n", i + 1);

        printf("Request ID: ");
        scanf("%d", &r[i].id);

        printf("Location: ");
        scanf(" %49[^\n]", &r[i].location);

        printf("People affected: ");
        scanf("%d", &r[i].people);

        printf("Emergency Level (1-Low, 2-Medium, 3-Critical): ");
        scanf("%d", &r[i].level);

        printf("Required Resources: ");
        scanf(" %49[^\n]", r[i].resources);

        printf("Assigned Team: ");
        scanf(" %49[^\n]", r[i].team);

        printf("Status: ");
        scanf(" %29[^\n]", r[i].status);
    }


    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (r[j].level < r[j + 1].level ||
               (r[j].level == r[j + 1].level &&
                r[j].people < r[j + 1].people))
            {
                temp = r[j];
                r[j] = r[j + 1];
                r[j + 1] = temp;
            }
        }
    }

    printf("\n--- PRIORITIZED RESCUE REQUESTS ---\n");

    for (int i = 0; i < n; i++)
    {
        printf("\nRequest ID: %d\n", r[i].id);
        printf("Location: %s\n", r[i].location);
        printf("People Affected: %d\n", r[i].people);
        printf("Emergency Level: %d\n", r[i].level);
        printf("Resources: %s\n", r[i].resources);
        printf("Assigned Team: %s\n", r[i].team);
        printf("Status: %s\n", r[i].status);
    }

    return 0;
}
