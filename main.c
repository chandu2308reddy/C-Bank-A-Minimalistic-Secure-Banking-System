#include <stdio.h>

char accountName[50];   
int accountNumber = 0;  
float balance = 0.0;    
int accountExists = 0;  
int accountPIN = 0;     


int validatePIN() {
    int enteredPIN;
    int attempts = 3;  
    while (attempts > 0) {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &enteredPIN);

        if (enteredPIN == accountPIN) {
            return 1;  
        } else {
            attempts--;
            if (attempts > 0) {
                printf("Incorrect PIN. Please try again. Attempts remaining: %d\n", attempts);
            }
        }
    }

    printf("Incorrect PIN entered 3 times. Access denied.\n");
    return 0;  
}

void createAccount() {
    printf("Enter account holder name: ");
    scanf("%s", accountName);
    accountNumber = 1;  
    balance = 0.0;
    accountExists = 1;  
    printf("Set a 4-digit PIN for your account: ");
    scanf("%d", &accountPIN);
    printf("Account created with number %d\n", accountNumber);
}

void deposit() {
    if (!accountExists) {
        printf("No account exists. Please create an account first.\n");
        return;
    }
    if (!validatePIN()) return;  

    float amount;
    printf("Enter deposit amount: ");
    scanf("%f", &amount);
    if (amount < 0) {
        printf("Deposit amount cannot be negative.\n");
        return;
    }
    balance += amount;
    printf("Amount deposited. New balance: %.2f\n", balance);
}

void withdraw() {
    if (!accountExists) {
        printf("No account exists. Please create an account first.\n");
        return;
    }
    if (!validatePIN()) return;  

    float amount;
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);
    if (amount < 0) {
        printf("Withdrawal amount cannot be negative.\n");
        return;
    }
    if (balance >= amount) {
        balance -= amount;
        printf("Withdrawal successful. New balance: %.2f\n", balance);
    } else {
        printf("Insufficient balance.\n");
    }
}

void checkBalance() {
    if (!accountExists) {
        printf("No account exists. Please create an account first.\n");
        return;
    }
    if (!validatePIN()) return;  

    printf("Account balance: %.2f\n", balance);
}

int main() {
    int choice;
    do {
        printf("\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
 
