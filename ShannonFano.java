//Still in progress, not completed yet.
public class ShannonFano {
    private int[] word;
    private String str;
    private static char[] array; //So, that reference is possible in static methods.
    private static int[] ascii;
    ShannonFano(int n, String text){
        word = new int[n];
        this.str = text;
        ascii = new int[text.length()];
    }
    public void toASCII(String text, char [] arr){
       char[] array = text.toCharArray();
       for(int i = 0; i < array.length; i++){
           //Converts the char array to ASCII values array.
           ascii[i] = array[i];
       }
        System.out.print("byte: ");
         for(int i = 0; i < text.length(); i++){
             System.out.print(ascii[i] + ","); 
         }
         System.out.println();
    }
    public void count(String text){ //Counts the numeber of occurences
        System.out.print("count: ");
         for(int i = 0; i < text.length(); i++){
            int count = compare(text,text.charAt(i));
            System.out.print(count + ", ");
        }
        System.out.println();
    }
    public int compare(String text, char a){
        int count = 0; 
        for(int i = 0; i < text.length(); i++){
            if(text.charAt(i) == a){
                count++;
            }
        }
        return count;
    }
    public void charSplit(String text){ //Prints the text character wise
        char[] array = text.toCharArray();
        System.out.print("char: ");
        for (int i = 0; i < array.length; i++){
            System.out.print(array[i] + ", ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        String name = "ABRACADABRA";
        System.out.println("Welcome to Shannon Fano");
        ShannonFano test = new ShannonFano(5,name);
        test.toASCII(name,array);
        test.charSplit(name);
        test.count(name);
    }
}
