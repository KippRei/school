import java.util.Scanner;

public class quiz1 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        boolean validInput = false;
        int numOfRowsInt = 0;

        do {
            System.out.println("Number of rows: ");
            String numOfRows = scan.nextLine();
            try {
                numOfRowsInt = Integer.parseInt(numOfRows);
                validInput = true; 
            } catch(NumberFormatException e) {
                System.out.println("Please enter a valid number.");
            }
        } while(!validInput);

        int numOfStars = 0;
        for (int i = 1; i <= numOfRowsInt; i++) {
            String output = "";
            numOfStars = i;
            for (int j = 1; j <= numOfRowsInt - numOfStars; j++) {
                output += " ";
            }
            for (int k = 1; k <= numOfStars; k++) {
                output += "*";
            }
            System.out.println(output);
        }
        scan.close();
    }
}