import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class A {
    public static void main(String[] args) {


        List<List<Integer>> M = new ArrayList<>();
        List<Integer> tmp1 = new ArrayList<>(Arrays.asList(5, 1, 5, 1));
        List<Integer> tmp2 = new ArrayList<>(Arrays.asList(3, 5, 3, 5));
        List<Integer> tmp3 = new ArrayList<>(Arrays.asList(4, 2, 1, 1));
        List<Integer> tmp4 = new ArrayList<>(Arrays.asList(1, 5, 1, 3));
        List<Integer> tmp5 = new ArrayList<>(Arrays.asList(1, 5, 3, 4));

        int i=5+3+5+2+5+5+3+4;
        System.out.println(i);
    }
}
