#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

// Command definitions
#define CONNECT_TO_LOBBY 1
#define PLAYER_POS_UPDATE 2
#define PLAYER_SHOOT_UP 3
#define SHOTS_FIRED 4
#define OPEN_DOOR 5
#define PICK_WEAPON 6
#define PICK_POWERUP 7
#define PICK_KEY 8
#define PICK_TREASURE 9
#define PLAYER_DISCONNECT 10
#define PLAYER_SCORE_UPDATE 11
#define PLAYER_UPDATE_PACKAGE 12
#define PLAYER_PICKUP_ITEM 13
#define PLAYER_DROP_ITEM 14
#define MISSILE_EXPLOTION 15
#define ELEMENT_SWITCH_POSITION 16
#define PLAYER_DIED 17
#define PLAYER_SHOOT_DOWN 18
#define START_MATCH 19
#define ENDING_MATCH 20

/*// PowerUp ID definitions
#define FOOD 30
#define MEDIKIT 31
#define BLOOD 32
#define BULLETS 33
#define CHEST 34
#define CROSS 35
#define CROWN 36
#define CUP 37
#define KEY 38*/

#define KEY_A_DOWN 100
#define KEY_D_DOWN 200
#define KEY_W_DOWN 300
#define KEY_S_DOWN 400
#define KEY_A_UP 500
#define KEY_D_UP 600
#define KEY_W_UP 700
#define KEY_S_UP 800
#define KEY_1_DOWN 101
#define KEY_2_DOWN 202
#define KEY_3_DOWN 303
#define KEY_4_DOWN 404
#define KEY_5_DOWN 505

// RESPONSE DEFINITIONS

#define CONNECTED_OK 1

#endif
