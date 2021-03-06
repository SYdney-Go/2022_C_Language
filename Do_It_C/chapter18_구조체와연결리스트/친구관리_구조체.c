#include <stdio.h>
#define MAX_COUNT   5

typedef struct People
{
    char name[14];
    unsigned short int age;
    float height;
    float weight;
} Person;


int AddFriend(Person *p_friend, int count)
{
    if(count<MAX_COUNT)
    {
        p_friend = p_friend + count;
        /*p_friend 구조체에 각각의 요소를 추가해주기*/
        printf("\n새로운 친구 정보를 입력하세요\n");
        printf("1. 이름 : ");
        scanf("%s", p_friend->name); 
        printf("2. 나이 : ");
        scanf("%hu", &p_friend->age);
        printf("3. 키 : ");
        scanf("%f", &p_friend->height);
        printf("4. 몸무게 : ");
        scanf("%f", &p_friend->weight);
        printf("입력을 완료했습니다. \n\n");
        return 1;
    }
    else
    {
        printf("최대 인원을 초과하여 입력을 할 수 없습니다. \n");
        printf("최대 %d명까지만 관리 가능합니다. \n\n", MAX_COUNT);
    }
    return 0;
}

void ShowFriendList(Person *p_friend, int count)
{
    int i;
    if(count > 0)
    {
        printf("\n등록된 친구 목록\n");
        printf("====================\n");
        for(i=0; i<count; i++)
        {
            printf("%-5s, %3d, %6.2f, %6.2f\n", 
                    p_friend->name, p_friend->age, p_friend->height, p_friend->weight);
            p_friend++;
        }
        printf("===================\n");
    }
    else
    {
        printf("\n등록된 친구가 없습니다.\n\n");
    }
}

void main()
{
    Person friend[MAX_COUNT];
    int count = 0, num;

    while(1)
    {
        printf("      [메뉴]      \n");
        printf("1. 친구 추가       \n");
        printf("2. 친구 목록 보기   \n");
        printf("3. 종료             \n");
        printf("===================\n");
        printf("번호 선택: : ");
        scanf("%d", &num);
        if(num == 1)
        {
            if(1==AddFriend(friend, count)) count++;
        }
        else if (num == 2)
        {
            ShowFriendList(friend, count);
        }
        else if(num == 3)
        {
            break;
        }
        else
        {
            printf("1 ~ 3 번호만 선택할 수 있습니다!!!\n\n");
        }
    }
}