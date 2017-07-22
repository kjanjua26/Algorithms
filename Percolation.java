/*
    Author: Kamran Janjua
    Assignment # 1. Princeton Course Intro to Algorithms Part 1. 
    To check the class, create a test client and then run with stats.
    Sites are open with probability p and closed with probability p-1.
*/
import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;
import edu.princeton.cs.algs4.WeightedQuickUnionUF;
public class Percolation {
    private int siteSize;
    private boolean[] sites; //blocked grid
    private int gridSize;
    private WeightedQuickUnionUF storage; //storage is grid.
    private int vTop;
    private int vBot;
    private int siteCount = 0;
    
    //Initialize the grid with all sites to be closed. 
    public Percolation(int n){
        siteSize = n;
        gridSize = n*n+2; //2 for top and bottom virtual sites. 
        WeightedQuickUnionUF storage = new WeightedQuickUnionUF(gridSize);
        sites = new boolean[n];
        for(int i = 0; i < sites.length; i++){
            sites[i] = false; //where 0 means that the site is closed. 
        } 
        vTop = n*n+1;
        vBot = n*n+2;
        connTop(sites, n); //Connects the virtual top to the first level sites.
        connBot(sites, n); //Connects the virual bottom to the last level sites.
    }
    
    public void opensite(int row, int col) throws IndexOutOfBoundsException{
        if(isOpen(row,col)) return;
        checkSite(row,col);
        int join = siteSize*(row-1) + (col-1);
        if(sites[join] == false){ //ensure that the site is blocked.
            sites[join] = true; //open the site.
            if(join % siteSize != 0){
                storage.union(join, join-1);
                siteCount++;
            }
            if(join >= siteSize){
                storage.union(join, join - siteSize);
                siteCount++;
            }
            if(join % siteSize != siteSize-1){
                storage.union(join, join+1);
                siteCount++;
            }
            if(join <= siteSize*(siteSize-1)){
                storage.union(join, join + siteSize);
                siteCount++;
            }
        }
        
    }
    public boolean isOpen(int row, int col){ //returns true for open and false for closed.
        checkSite(row,col);
        return sites[(row-1)*siteSize + col-1];
    }
    public boolean isFull(int row, int col){
        checkSite(row,col);
        return storage.connected((row-1)*siteSize + col-1, vTop);
    }
    public int numberOfOpenSites(){
        return siteCount;
    }
    public boolean percolates(){
        return storage.connected(vTop, vBot);
    }
    private void unite(int i, int j){ 
        //Checks if the two nodes are connected or not.
        //If they are connected, then it connects/unions them. 
        if(!storage.connected(i,j)){
            storage.union(i, j);
        }
    }
    private void connTop(boolean[] sites, int N){ //Connects the vTop to first layer
        for(int i = 0; i < N; i++){
            storage.union(vTop, i);
        }
    }
     private void connBot(boolean[] sites, int N){ //Connects the vTop to first layer
        for(int i = 0; i < N; i++){
            storage.union(vBot, (N*N)-N+i); //The bottom layer
        }
    }
    private void checkSite(int i, int j){
        if(( i < 1 || i > siteSize) || (j < 1 || j > siteSize)){
                throw new IndexOutOfBoundsException();
        }
    }
}
  
