#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "20070001033.h"

int roll_the_dice(){
    int num;
    num = (rand() % 6) + 1;
    return num;
}

enum Hit get_hit_type(){
	int num = (rand()%100) +1;
	if(num<=75){
		return 0;
	}else if (num >75&&num <=95){
		return 1;
	}else return 2;
	
    /*
     * TODO: Randomly choose a hit type
     *   Probability of a NORMAL hit: %75
     *   Probability of a CRITICAL hit: %20
     *   Probability of a HEADSHOT: %5
     *
     * TODO: return the hit type
    */
}

enum Weapon choose_weapon(){
    int weapon;
    printf("Choose a weapon: 1-Knife 2-Gun 3-Grenade\n");
    scanf("%d",&weapon);
    return weapon;
}

int attack(int enemy_health, enum Weapon weapon){
    enum Hit hitType;
    int damage;

    if(weapon == Knife){
        damage = KNIFE_DMG;
    }
    else if(weapon == Gun){
        damage = GUN_DMG;
    }
    else if(weapon == Grenade){
        damage = GRENADE_DMG;
    }

    hitType = get_hit_type();
    int b;
    b = (rand() %100);
    if(b <75 ){
	return Normal;
	} else if (b >75 &&b<=95){
	return Critical;
		
	}else return Headshot;
	

    
    

    /*
     * TODO: Modify the damage according to the hit type
     *   NORMAL hit does not change the damage
     *   CRITICAl hit doubles the damage
     *   HEADSHOT kills the enemy immediately
     */

    printf("Hits with damage : %d\n", damage);

    enemy_health = enemy_health - damage;
    if(enemy_health < DEAD){
        enemy_health = DEAD;
    }
    return enemy_health;
}

void game(){
    int p1_dice,p2_dice;
    int p1_health,p2_health;
    int weapon;
    int i;

    p1_health = FULL_HEALTH;
    p2_health = FULL_HEALTH;

    printf("The health of p1 : %d\n", p1_health);
    printf("The health of p2 : %d\n", p2_health);
    if(p2_health ==0){
    	printf("winner ->P1\n");
    	printf("-------------------\n");
    	}else if (p1_health ==0)
{
	printf("winner ->P2\n");
	printf("-------------------");
}
    /*
     * TODO: Continue the game until a player dies
     * TODO: Announce the winner
     */

    do{
        p1_dice = roll_the_dice();
        p2_dice = roll_the_dice();
    }while(p1_dice == p2_dice);

    printf("The player 1 rolling the dice...:");
    for(i = 0 ; i<100000000; i++);
    printf("%d\n",p1_dice);

    printf("The player 2 rolling the dice...:");
    for(i = 0 ; i<100000000; i++);
    printf("%d\n",p2_dice);

    if(p1_dice>p2_dice){
        printf("PLAYER 1's Turn\n");
        weapon = choose_weapon();
        p2_health = attack(p2_health,weapon-1);
    }
    else if(p2_dice>p1_dice){
        printf("PLAYER 2's Turn\n");
        weapon = choose_weapon();
        p1_health = attack(p1_health,weapon-1);
    }

    printf("Player 1's health : %d\n",p1_health);
    printf("Player 2's health : %d\n",p2_health);
    printf("--------------------------\n");

}

int main(){
    srand(time(NULL));
    game();

    return 0;
}


