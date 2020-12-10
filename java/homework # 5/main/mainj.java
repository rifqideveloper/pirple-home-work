package main;
//import java.util.ArrayList;

import java.util.concurrent.ThreadLocalRandom;

public class mainj {
    public static void main(String[] args) {
        String test = "abc";
        short min = 0,max = 10;
        System.out.println(reverseString(test));
        System.out.println(isPalindrome(test));
        System.out.println(randBetween(min, max));
    }

    public static String reverseString(String word) {
        byte[] strAsByteArray = word.getBytes();
        byte[] result = new byte[strAsByteArray.length];
        for (int i = 0; i < strAsByteArray.length; i++)
            result[i] = strAsByteArray[strAsByteArray.length - i - 1];
        return new String(result);

    }

    public static boolean isPalindrome(String word) {
        int i = 0, j = word.length() - 1;
        while (i < j) {
            if (word.charAt(i) != word.charAt(j))
                return false;
            i++;
            j--;
        }
        return true;
    }

    public static int randBetween(int min, int max) {
        return ThreadLocalRandom.current().nextInt(min, max + 1);
    }

}

