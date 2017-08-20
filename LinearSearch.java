/*
    Finds and prints the index of the last occurrence of element M
    in the array if it exists in it, otherwise print -1.
 */
package com.company;
import java.util.Scanner;
public class LinearSearch {
    private static int n[] = {2,3,4,5};
    private int ele;
    LinearSearch(int ele){
        this.ele = ele;
    }
    public int searchElement(int[] arr, int ele){
        int index, element;
        for(int i = 0; i < arr.length; i++){
            if(arr[i] == ele){
                index = i;
                element  = arr[i];
                return i;
            }
        }
        return 0;
    }
    public int printElement(){
        int index = searchElement(n,ele);
        if(n[index] == ele){
            return index;
        }
        else{
            return -1;
        }
    }
    public static void main(String[] args) {
        LinearSearch test = new LinearSearch(5);
        int out = test.printElement();
        System.out.println("The output is: " + out);
    }
}
