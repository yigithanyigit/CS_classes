#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab-07.h"

int roll_the_dice(){
    /**
        Rolls a dice and returns between [1,6]
        @return  -> num
    */
    int num;
    num = (rand() % 6) + 1;
    return num;
}


enum Hit get_hit_type(){
/**
    - Implement the get_hit_type function
        . It should probabilistically choose a hit type
        . Hit types are given as an enumeration
        . Probability of a NORMAL hit: 75%
        . Probability of a CRITICAL hit: 20%
        . Probability of a HEADSHOT : 5%
        . Return the hit type

        @return  -> NORMAL, CRITICAL, HEADSHOT respectively
*/
   int num = (rand() % 100) + 1;
   if (num <= 75){
       return 0;
   }else if (num > 75 && num <= 95){
       return 1;
   }else return 2;

}

enum Weapon choose_weapon(){
    /**
    ----------- BONUS !!!! ---------------
    I personally add selection probabilty to weapons. Also i added 'punch' to weapons to balance game. Punch damage is 5;
    --------------------------------------
    Percentages:
        Grenade %30
        Gun %40
        Knife %70
    Select weapon that do you want, then dice will roll if lucky enough then you get weapon, if you can't you need to punch it :)

    @return  -> Knife, Gun, Grenade, Punch respectively
    */
    int weapon;
    printf("Choose a weapon: 1-Knife 2-Gun 3-Grenade\n");
    scanf("%d",&weapon);
    int dice = (rand() % 100 ) + 1;
    if (weapon == Grenade && dice < 31){
        return weapon;
    }else if(weapon == Gun && dice < 41){
        return weapon;
    }else if(weapon == Knife && dice < 71){
        return weapon;
    }else return 4;
    
}

int attack(int enemy_health, enum Weapon weapon){
    /**
    - In attack function
        . get a git type by calling the get_hit_type function
        . modify the damage according to the hit type
        . NORMAL hit does not change the damage
        . CRITICAl hit doubles the damage
        . HEADSHOT kills the enemy immediately
    ----------- BONUS !!!! ---------------
    Punch can not headshot
    --------------------------------------
    @params -> int enemy_health, enum Weapon weapon
    @return -> enemy_health
    */
    enum Hit hitType;
    int damage;

    if(weapon == Knife){
        printf("Weapon is Knife\n");
        damage = KNIFE_DMG;
    }
    else if(weapon == Gun){
        printf("Weapon is Gun\n");
        damage = GUN_DMG;
    }
    else if(weapon == Grenade){
        printf("Weapon is Grenade\n");
        damage = GRENADE_DMG;
    }
    else if(weapon == Punch){
        printf("Weapon is Punch\n");
        damage = PUNCH_DMG;
    }

    hitType = get_hit_type();

    if ( hitType == Critical){
        printf("\n*************************************\n");
        printf("************CRITICAL*****************\n");
        printf("*************************************\n");
        damage *= 2;
    } else if(hitType == Headshot && weapon != Punch){
        printf("\n*************************************\n");
        printf("************HEADSHOT*****************\n");
        printf("*************************************\n");
        damage = 100;
    }
    printf("Hits with damage : %d\n", damage);

    enemy_health = enemy_health - damage;
    if(enemy_health < DEAD){
        enemy_health = DEAD;
    }
    return enemy_health;
}


int heal(int health)
{
    /**
    ----------- BONUS !!!! ---------------
    healing 10 points, if lucky enough roll a dice and get 6 then get FAITH buff which is heal all health
    --------------------------------------

    @params -> int health
    @return -> health


    */
    int dice = roll_the_dice();
    if(dice == 6)
    {
        printf("\n*************************************\n");
        printf("*************FAITH BONUS*************\n");
        printf("********HEALTH FULLY RESTORED********\n");
        printf("*************************************\n");
       return 100; 
    }else if (health != 100)
    {   
        if(health + 10 > 100){
            printf("healed %d points, new health %d \n", 100 - health, health + (100 - health));
            return health + (100 - health);
        }else{
        printf("healed 10 points, new health %d \n", health + 10); 
        return health += 10;
        }
    }else return health;
    

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

    while (p1_health != 0 && p2_health != 0)
    {
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
        

        int decision;


        if(p1_dice>p2_dice){
            printf("PLAYER 1's Turn\n");
            printf("----------------------------------------\n");
            printf("HEAL OR ATTACK? 1-ATTACK 2-HEAL\n");
            scanf_s("%d", &decision);
            if (decision == 1)
            {
                weapon = choose_weapon();
                p2_health = attack(p2_health,weapon-1);
            }else 
            {
                p1_health = heal(p1_health);
            }
                        

        }
        else if(p2_dice>p1_dice){
            printf("PLAYER 2's Turn\n");
            printf("----------------------------------------\n");
            printf("HEAL OR ATTACK? 1-ATTACK 2-HEAL\n");
            scanf_s("%d", &decision);
            if (decision == 1)
            {
                weapon = choose_weapon();
                p1_health = attack(p1_health,weapon-1);
            }else 
            {
                p2_health = heal(p2_health);
            }
        }

        printf("Player 1's health : %d\n",p1_health);
        printf("Player 2's health : %d\n",p2_health);
        printf("--------------------------\n");
    }
    if(p2_health == 0){
    printf("winner -> P1 \n");
    printf("--------------------------\n");
    }else if (p1_health == 0)
    {
    printf("winner -> P2 \n");
    printf("--------------------------\n");
    }
    }


int main(){
    srand(time(NULL));
    game();

    return 0;
}