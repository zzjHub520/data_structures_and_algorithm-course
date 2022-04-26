import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Objects;

public class 被盗的房屋编号 {
    public static void main(String[] args) {
        //2,5,7,9(matlab)
        //1,4,6,8
        //int[] arr = {2, 7, 2, 3, 8, 4, 7, 5, 9, 6};
        List<Integer> intList = new ArrayList<>(Arrays.asList(2, 7, 2, 3, 8, 4, 7, 5, 9, 6));
        //intList.add(2);
        System.out.println(houseRobber(intList));
    }

    public static int houseRobber(List<Integer> intList) {
        List<Integer> index = new ArrayList<>();
        if (intList.size() == 1) {
            index.add(0);
            System.out.println(index);
            return intList.get(0);
        } else if (intList.size() == 2) {
            int tmp = intList.get(0) > intList.get(1) ? 0 : 1;
            index.add(tmp);
            System.out.println(index);
            return intList.get(tmp);
        } else {
            List<Integer> dp = new ArrayList<>();
            dp.add(intList.get(0));
            dp.add(Math.max(intList.get(0), intList.get(1)));

            for (int i = 2; i < intList.size(); ++i) {
                dp.add(Math.max(dp.get(i - 1), dp.get(i - 2) + intList.get(i)));
            }

            intList.add(1);
            Integer tmp = dp.get(dp.size() - 1);
            dp.add(tmp + 1);
            int value = dp.size() - 1;

            for (int i = dp.size() - 2; i >= 0; --i) {

//                if (i != 0 && Objects.equals(dp.get(i), dp.get(i - 1))) {
//                    System.out.println("===");
//                } else if (dp.get(value) - intList.get(value) == dp.get(i)) {
//                    index.add(i);
//                    value = i;
//                }

                if ((!(i != 0 && Objects.equals(dp.get(i), dp.get(i - 1)))) && (dp.get(value) - intList.get(value) == dp.get(i))) {
                    index.add(i);
                    value = i;
                }
            }
            System.out.println(index);
            return dp.get(dp.size() - 1);
        }
    }
}
