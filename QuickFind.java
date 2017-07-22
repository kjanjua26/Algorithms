/*
    QuickFind Implementation. 
*/
public class QuickFind {
    private int[] array;
        public QuickFind(int N){            
            array = new int[N];
            for(int i = 0; i < N; i++){
                array[i] = i;
            }
        }
    public boolean connected(int p, int q){
        return array[p] == array[q];
    }
    public void union(int p, int q){
        int idp = array[p];
        int idq = array[q];
        for(int i = 0; i < array.length; i++){
            if (array[i] == idp)
                array[i] = idq;
        }
    }
    public static void main(String[]args){
        QuickFind test = new QuickFind(10); //Initializing the array.
        test.union(1,3);
        boolean res = test.connected(1,3);
        System.out.println("The connection is: " + res);
    }
}