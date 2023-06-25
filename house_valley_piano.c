#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYER_LEN 20
#define MAX_TEAM_MEMBER 20
#define MAX_TEAMS 5

// Structures
typedef struct {
    char playerName[MAX_PLAYER_LEN];
    int age;
    float height;
    float weight;
    int strength;
    int agility;
    int speed;
    int quickness;
    int conditioning;
    int recovery;
} Player;

typedef struct {
    char teamName[MAX_PLAYER_LEN];
    Player teamMembers[MAX_TEAM_MEMBER];
    int teamSize;
} Team;

// Function declarations
Team *createTeams();
Player createPlayer();
void printTeams(Team *teams);
void deleteTeams(Team *teams);
int getTeamStrength(Team team);
int getTeamAgility(Team team);
float getTeamHeight(Team team);
float getTeamWeight(Team team);
int getTeamSpeed(Team team);
int getTeamQuickness(Team team);
int getTeamConditioning(Team team);
int getTeamRecovery(Team team);
int performStrengthTraining(Team *team);
int performAgilityTraining(Team *team);
float performHeightTraining(Team *team);
float performWeightTraining(Team *team);
int performSpeedTraining(Team *team);
int performQuicknessTraining(Team *team);
int performConditioningTraining(Team *team);
int performRecoveryTraining(Team *team);
void trainTeam(Team *team);

// Main function
int main(void) {
    Team *teams;

    teams = createTeams();
    printTeams(teams);
    trainTeam(teams);
    printTeams(teams);

    deleteTeams(teams);

    return 0;
}

// Function definitions
Team *createTeams() {
    Team *teams;
    int i, j;

    teams = (Team *)malloc(MAX_TEAMS * sizeof(Team));
    for (i = 0; i < MAX_TEAMS; i++) {
        sprintf(teams[i].teamName, "Team %d", i+1);
        teams[i].teamSize = 0;
        for (j = 0; j < MAX_TEAM_MEMBER; j++) {
            teams[i].teamMembers[j] = createPlayer();
        }
    }

    return teams;
}

Player createPlayer() {
    Player player;
    int seed = time(NULL);

    srand(seed);

    sprintf(player.playerName, "Player %d", rand() % 10);
    player.age = rand() % 10;
    player.height = (float)(rand() % 100) / 10;
    player.weight = (float)(rand() % 100) / 10;
    player.strength = rand() % 10;
    player.agility = rand() % 10;
    player.speed = rand() % 10;
    player.quickness = rand() % 10;
    player.conditioning = rand() % 10;
    player.recovery = rand() % 10;

    return player;
}

void printTeams(Team *teams) {
    int i, j;

    for (i = 0; i < MAX_TEAMS; i++) {
        printf("Team: %s\n", teams[i].teamName);
        printf("  Player Name    Age  Ht  Wt  Str Agi Spd Qui Con Rec\n");
        printf("  ------------- ----- --- --- --- --- --- --- --- ---\n");
        for (j = 0; j < MAX_TEAM_MEMBER; j++) {
            printf("  %-13s %2d %3.1f %3.1f %3d %3d %3d %3d %3d %3d\n",
                    teams[i].teamMembers[j].playerName,
                    teams[i].teamMembers[j].age,
                    teams[i].teamMembers[j].height,
                    teams[i].teamMembers[j].weight,
                    teams[i].teamMembers[j].strength,
                    teams[i].teamMembers[j].agility,
                    teams[i].teamMembers[j].speed,
                    teams[i].teamMembers[j].quickness,
                    teams[i].teamMembers[j].conditioning,
                    teams[i].teamMembers[j].recovery);
        }
        printf("\n");
    }
}

void deleteTeams(Team *teams) {
    free(teams);
}

int getTeamStrength(Team team) {
    int i, strength = 0;

    for (i = 0; i < MAX_TEAM_MEMBER; i++) {
        strength += team.teamMembers[i].strength;
    }

    return strength / MAX_TEAM_MEMBER;
}

int getTeamAgility(Team team) {
    int i, agility = 0;

    for (i = 0; i < MAX_TEAM_MEMBER; i++) {
        agility += team.teamMembers[i].agility;
    }

    return agility / MAX_TEAM_MEMBER;
}

float getTeamHeight(Team team) {
    int i;
    float height = 0.0;

    for (i = 0; i < MAX_TEAM_MEMBER; i++) {
        height += team.teamMembers[i].height;
    }

    return height / MAX_TEAM_MEMBER;
}

float getTeamWeight(Team team) {
    int i;
    float weight = 0.0;

    for (i = 0; i < MAX_TEAM_MEMBER; i++) {
        weight += team.teamMembers[i].weight;
    }

    return weight / MAX_TEAM_MEMBER;
}

int getTeamSpeed(Team team) {
    int i, speed = 0;

    for (i = 0; i < MAX_TEAM_MEMBER; i++) {
        speed += team.teamMembers[i].speed;
    }

    return speed / MAX_TEAM_MEMBER;
}

int getTeamQuickness(Team team) {
    int i, quickness = 0;

    for (i = 0; i < MAX_TEAM_MEMBER; i++) {
        quickness += team.teamMembers[i].quickness;
    }

    return quickness / MAX_TEAM_MEMBER;
}

int getTeamConditioning(Team team) {
    int i, conditioning = 0;

    for (i = 0; i < MAX_TEAM_MEMBER; i++) {
        conditioning += team.teamMembers[i].conditioning;
    }

    return conditioning / MAX_TEAM_MEMBER;
}

int getTeamRecovery(Team team) {
    int i, recovery = 0;

    for (i = 0; i < MAX_TEAM_MEMBER; i++) {
        recovery += team.teamMembers[i].recovery;
    }

    return recovery / MAX_TEAM_MEMBER;
}

int performStrengthTraining(Team *team) {
    int i;
    int strength = 0;

    for (i = 0; i < MAX_TEAM_MEMBER; i++) {
        team->teamMembers[i].strength++;
        strength += team->teamMembers[i].strength;
    }

    return strength / MAX_TEAM_MEMBER;
}

int performAgilityTraining(Team *team) {
    int i;
    int agility = 0;

    for (i = 0; i < MAX_TEAM_MEMBER; i++) {
        team->teamMembers[i].agility++;
        agility += team->teamMembers[i].agility;
    }

    return agility / MAX_TEAM_MEMBER;
}

float performHeightTraining(Team *team) {
    int i;
    float height = 0.0;

    for (i = 0; i < MAX_TEAM_MEMBER; i++) {
        team->teamMembers[i].height += 0.1;
        height += team->teamMembers[i].height;
    }

    return height / MAX_TEAM_MEMBER;
}

float performWeightTraining(Team *team) {
    int i;
    float weight = 0.0;

    for (i = 0; i < MAX_TEAM_MEMBER; i++) {
        team->teamMembers[i].weight += 0.1;
        weight += team->teamMembers[i].weight;
    }

    return weight / MAX_TEAM_MEMBER;
}

int performSpeedTraining(Team *team) {
    int i;
    int speed = 0;

    for (i = 0; i < MAX_TEAM_MEMBER; i++) {
        team->teamMembers[i].speed++;
        speed += team->teamMembers[i].speed;
    }

    return speed / MAX_TEAM_MEMBER;
}

int performQuicknessTraining(Team *team) {
    int i;
    int quickness = 0;

    for (i = 0; i < MAX_TEAM_MEMBER; i++) {
        team->teamMembers[i].quickness++;
        quickness += team->teamMembers[i].quickness;
    }

    return quickness / MAX_TEAM_MEMBER;
}

int performConditioningTraining(Team *team) {
    int i;
    int conditioning = 0;

    for (i = 0; i < MAX_TEAM_MEMBER; i++) {
        team->teamMembers[i].conditioning++;
        conditioning += team->teamMembers[i].conditioning;
    }

    return conditioning / MAX_TEAM_MEMBER;
}

int performRecoveryTraining(Team *team) {
    int i;
    int recovery = 0;

    for (i = 0; i < MAX_TEAM_MEMBER; i++) {
        team->teamMembers[i].recovery++;
        recovery += team->teamMembers[i].recovery;
    }

    return recovery / MAX_TEAM_MEMBER;
}

void trainTeam(Team *team) {
    int strength, agility, speed, quickness, conditioning, recovery;

    printf("\nTraining Team: %s\n", team->teamName);
    printf("  Initial - Str: %d, Agi: %d, Spd: %d, Qui: %d, Con: %d, Rec: %d\n",
            getTeamStrength(*team),
            getTeamAgility(*team),
            getTeamSpeed(*team),
            getTeamQuickness(*team),
            getTeamConditioning(*team),
            getTeamRecovery(*team));

    performStrengthTraining(team);
    performAgilityTraining(team);
    performHeightTraining(team);
    performWeightTraining(team);
    performSpeedTraining(team);
    performQuicknessTraining(team);
    performConditioningTraining(team);
    performRecoveryTraining(team);

    strength = getTeamStrength(*team);
    agility = getTeamAgility(*team);
    speed = getTeamSpeed(*team);
    quickness = getTeamQuickness(*team);
    conditioning = getTeamConditioning(*team);
    recovery = getTeamRecovery(*team);

    printf("  Final   - Str: %d, Agi: %d, Spd: %d, Qui: %d, Con: %d, Rec: %d\n\n",
            strength, agility, speed, quickness, conditioning, recovery);
}