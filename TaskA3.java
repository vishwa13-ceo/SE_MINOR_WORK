public class TaskA3 {

    // This method performs division and checks for division by zero
    public static int divide(int numerator, int denominator) {
        if (denominator == 0) {
            System.out.println("Error: Can't divide by zero!"); 
            return -1; 
        }
        return numerator / denominator; 
    }

    // This method creates an array of integers with the specified size
    public static int[] createArray(int size) {
        return new int[size]; 
    }

    public static void main(String[] args) {
        int num1 = 10;
        int num2 = 0; // This will cause a division error

        int result = divide(num1, num2);
        if (result != -1) {
            System.out.println("Result of division: " + result);
        } else {
            System.out.println("Could not perform division due to an error."); 
        }

        // Now, let's create an array and fill it with some values
        int[] array = createArray(5);

        
        for (int i = 0; i < array.length; i++) {
            array[i] = i * 10; 
            System.out.println("Array[" + i + "] = " + array[i]); 
        }
    }
}
