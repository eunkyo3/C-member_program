#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 최대 회원 수
#define MAX_MEMBERS 100

// 회원 정보 구조체
struct Member {
    int id;
    char name[50];
    char gender[10];
    char email[100];
    char phone[20];
};

// 전역 변수: 회원 배열과 회원 수
struct Member members[MAX_MEMBERS];
int numMembers = 0;

// 회원 추가 함수
void addMember() {
    if (numMembers >= MAX_MEMBERS) {
        printf("더 이상 회원을 추가할 수 없습니다.\n");
        return;
    }

    struct Member newMember;
    newMember.id = numMembers + 1;

    printf("이름을 입력하세요: ");
    scanf("%s", newMember.name);

    printf("성별을 입력하세요: ");
    scanf("%s", newMember.gender);

    printf("이메일을 입력하세요: ");
    scanf("%s", newMember.email);

    printf("전화번호를 입력하세요: ");
    scanf("%s", newMember.phone);

    members[numMembers++] = newMember;
    printf("회원이 추가되었습니다.\n");
}

// 회원 조회 함수
void viewMembers() {
    if (numMembers == 0) {
        printf("등록된 회원이 없습니다.\n");
        return;
    }

    printf("\n");
    printf("============================================\n");
    printf("| ID  |  이름  |  성별  |  이메일            |  전화번호      |\n");
    printf("============================================\n");
    for (int i = 0; i < numMembers; i++) {
        printf("| %2d  | %-10s | %-5s | %-20s | %-12s |\n", members[i].id, members[i].name, members[i].gender, members[i].email, members[i].phone);
    }
    printf("============================================\n");
}

// 회원 삭제 함수
void deleteMember(int id) {
    // 회원 목록을 순회하며 입력한 ID와 일치하는 회원을 찾습니다.
    for (int i = 0; i < numMembers; i++) {
        if (members[i].id == id) {
            // 회원을 찾았을 경우, 해당 회원을 삭제합니다.

            // 삭제할 회원 뒤의 모든 회원을 한 칸씩 앞으로 이동시켜 덮어쓰고,
            for (int j = i; j < numMembers - 1; j++) {
                members[j] = members[j + 1];
            }

            // 회원 수를 줄이고 삭제 완료 메시지를 출력합니다.
            numMembers--;
            printf("회원(ID: %d)이 삭제되었습니다.\n", id);
            return; // 함수를 종료합니다.
        }
    }

    // 입력한 ID와 일치하는 회원을 찾지 못했을 경우, 에러 메시지를 출력합니다.
    printf("해당 ID의 회원을 찾을 수 없습니다.\n");
}


// 회원 수정 함수
void editMember(int id) {
    for (int i = 0; i < numMembers; i++) {
        if (members[i].id == id) {
            printf("새 이름을 입력하세요: ");
            scanf("%s", members[i].name);

            printf("새 성별을 입력하세요: ");
            scanf("%s", members[i].gender);

            printf("새 이메일을 입력하세요: ");
            scanf("%s", members[i].email);

            printf("새 전화번호를 입력하세요: ");
            scanf("%s", members[i].phone);

            printf("회원(ID: %d) 정보가 수정되었습니다.\n", id);
            return;
        }
    }
    printf("해당 ID의 회원을 찾을 수 없습니다.\n");
}

// 메인 함수
int main() {
    int choice;

    while (1) {
        printf("\n");
        printf("================================\n");
        printf("   회원 관리 프로그램\n");
        printf("================================\n");
        printf("1. 회원 추가\n");
        printf("2. 회원 조회\n");
        printf("3. 회원 삭제\n");
        printf("4. 회원 수정\n");
        printf("5. 종료\n");
        printf("================================\n");
        printf("선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addMember();
            break;
        case 2:
            viewMembers();
            break;
        case 3:
        {
            int id;
            printf("삭제할 회원의 ID를 입력하세요: ");
            scanf("%d", &id);
            deleteMember(id);
        }
        break;
        case 4:
        {
            int id;
            printf("수정할 회원의 ID를 입력하세요: ");
            scanf("%d", &id);
            editMember(id);
        }
        break;
        case 5:
            printf("프로그램을 종료합니다.\n");
            exit(0);
        default:
            printf("잘못된 선택입니다. 다시 선택하세요.\n");
        }
    }

    return 0;
}