package BankAccountCreator;
import java.util.Scanner;

/**
 * BankAccount
 */
public class BankAccount {
    String accountType;
    String accountNum;
    String accountCreateDate;
    String custFirstName;
    String custLastName;
    String custDOB;
    String custLastFour;
    String custAddress;
    Scanner scan = new Scanner(System.in);

    void setAccountType() {
        Boolean validInput = false;
        do {
            System.out.println("Account type: (savings/checking)");
            String userInput = scan.nextLine().toLowerCase();
            if (userInput == "savings" || userInput == "checking") {
                accountType = userInput;
                validInput = true;
            }
            else {
                errorMessage("account type");
            }
        } while(!validInput);
    }

    void errorMessage(String errorType) {
        System.out.println("Invalid " + errorType + ", please try again.");
    }
}