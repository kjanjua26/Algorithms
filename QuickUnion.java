/*
    Implementation of Quick Union.
*/
public class QuickUnion {
    private int[] array;
    public QuickUnion(int N){
        array = new int[N];
        for(int i = 0; i < N; i++){
            array[i] = i;
        }
    }
    private int root(int i){
        while(i != array[i]){
            i = array[i];
        }
        return i;
    }
    public boolean connected(int p, int q){
        return root(p) == root(q);
    }
    public void union(int p, int q){
        int rp = root(p);
        int rq = root(q);
        array[rp] = rq;
    }
    public static void main(String[] args) {
        QuickUnion test = new QuickUnion(10);
        test.union(1, 2);
        test.union(6, 7);
        test.union(2, 3);
        test.union(5, 4);
        test.union(6, 5);
        test.union(5, 3);
        System.out.println(test.connected(3,6));
        
    }
    
}
