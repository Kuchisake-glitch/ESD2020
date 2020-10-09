import java.util.*;
import javax.swing.JOptionPane;

public class Factorial{

public static void main(String args[]){
   int num;
   do{
      String sfact =JOptionPane.showInputDialog(null,"Digite numero entero positivo");
      num= Integer.parseInt(sfact);
      }while(num<0);
      JOptionPane.showMessageDialog(null,"Factorial de " + num + "! = " + factorial(num), "calculo de factorial",JOptionPane.INFORMATION_MESSAGE);
   }
   
   static long factorial(int n){
   if(n<=1)
      return 1;
   else
      return n*factorial(n-1);
   }
}