/*
    Peak and Edge Finder in 1D Array
 */
package com.company;
public class PeakFinder {
    private int array[];
    private int n;
    Main(int a, int n[]){
        int[] array = new int[a];
    }
    public void checkPeak(int index, int[] n){
        if(n[index] >= n[index+1] && n[index] >= n[index-1]) {
            System.out.println("It is a peak: " + n[index]);
        }
        else{
            System.out.println("Not a peak: " + n[index]);
        }
    }
    public void checkEdge(int index, int[] n){
        if(n[index] >= n[index-1]){
            System.out.println("It is an edge: " + n[index]);
        }
        else{
            System.out.println("It is not an edge: " + n[index]);
        }
    }
    public static void main(String[] args) {
        int[] a = {1,2,8,5,6}; //test array.
        PeakFinder test = new PeakFinder(5,a); //Initializing the array
        test.checkPeak(1,a); //Passing the index and array.
        test.checkEdge(4,a);
    }
}
