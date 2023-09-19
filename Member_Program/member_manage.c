#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ִ� ȸ�� ��
#define MAX_MEMBERS 100

// ȸ�� ���� ����ü
struct Member {
    int id;
    char name[50];
    char gender[10];
    char email[100];
    char phone[20];
};

// ���� ����: ȸ�� �迭�� ȸ�� ��
struct Member members[MAX_MEMBERS];
int numMembers = 0;

// ȸ�� �߰� �Լ�
void addMember() {
    if (numMembers >= MAX_MEMBERS) {
        printf("�� �̻� ȸ���� �߰��� �� �����ϴ�.\n");
        return;
    }

    struct Member newMember;
    newMember.id = numMembers + 1;

    printf("�̸��� �Է��ϼ���: ");
    scanf("%s", newMember.name);

    printf("������ �Է��ϼ���: ");
    scanf("%s", newMember.gender);

    printf("�̸����� �Է��ϼ���: ");
    scanf("%s", newMember.email);

    printf("��ȭ��ȣ�� �Է��ϼ���: ");
    scanf("%s", newMember.phone);

    members[numMembers++] = newMember;
    printf("ȸ���� �߰��Ǿ����ϴ�.\n");
}

// ȸ�� ��ȸ �Լ�
void viewMembers() {
    if (numMembers == 0) {
        printf("��ϵ� ȸ���� �����ϴ�.\n");
        return;
    }

    printf("\n");
    printf("============================================\n");
    printf("| ID  |  �̸�  |  ����  |  �̸���            |  ��ȭ��ȣ      |\n");
    printf("============================================\n");
    for (int i = 0; i < numMembers; i++) {
        printf("| %2d  | %-10s | %-5s | %-20s | %-12s |\n", members[i].id, members[i].name, members[i].gender, members[i].email, members[i].phone);
    }
    printf("============================================\n");
}

// ȸ�� ���� �Լ�
void deleteMember(int id) {
    // ȸ�� ����� ��ȸ�ϸ� �Է��� ID�� ��ġ�ϴ� ȸ���� ã���ϴ�.
    for (int i = 0; i < numMembers; i++) {
        if (members[i].id == id) {
            // ȸ���� ã���� ���, �ش� ȸ���� �����մϴ�.

            // ������ ȸ�� ���� ��� ȸ���� �� ĭ�� ������ �̵����� �����,
            for (int j = i; j < numMembers - 1; j++) {
                members[j] = members[j + 1];
            }

            // ȸ�� ���� ���̰� ���� �Ϸ� �޽����� ����մϴ�.
            numMembers--;
            printf("ȸ��(ID: %d)�� �����Ǿ����ϴ�.\n", id);
            return; // �Լ��� �����մϴ�.
        }
    }

    // �Է��� ID�� ��ġ�ϴ� ȸ���� ã�� ������ ���, ���� �޽����� ����մϴ�.
    printf("�ش� ID�� ȸ���� ã�� �� �����ϴ�.\n");
}


// ȸ�� ���� �Լ�
void editMember(int id) {
    for (int i = 0; i < numMembers; i++) {
        if (members[i].id == id) {
            printf("�� �̸��� �Է��ϼ���: ");
            scanf("%s", members[i].name);

            printf("�� ������ �Է��ϼ���: ");
            scanf("%s", members[i].gender);

            printf("�� �̸����� �Է��ϼ���: ");
            scanf("%s", members[i].email);

            printf("�� ��ȭ��ȣ�� �Է��ϼ���: ");
            scanf("%s", members[i].phone);

            printf("ȸ��(ID: %d) ������ �����Ǿ����ϴ�.\n", id);
            return;
        }
    }
    printf("�ش� ID�� ȸ���� ã�� �� �����ϴ�.\n");
}

// ���� �Լ�
int main() {
    int choice;

    while (1) {
        printf("\n");
        printf("================================\n");
        printf("   ȸ�� ���� ���α׷�\n");
        printf("================================\n");
        printf("1. ȸ�� �߰�\n");
        printf("2. ȸ�� ��ȸ\n");
        printf("3. ȸ�� ����\n");
        printf("4. ȸ�� ����\n");
        printf("5. ����\n");
        printf("================================\n");
        printf("�����ϼ���: ");
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
            printf("������ ȸ���� ID�� �Է��ϼ���: ");
            scanf("%d", &id);
            deleteMember(id);
        }
        break;
        case 4:
        {
            int id;
            printf("������ ȸ���� ID�� �Է��ϼ���: ");
            scanf("%d", &id);
            editMember(id);
        }
        break;
        case 5:
            printf("���α׷��� �����մϴ�.\n");
            exit(0);
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
        }
    }

    return 0;
}