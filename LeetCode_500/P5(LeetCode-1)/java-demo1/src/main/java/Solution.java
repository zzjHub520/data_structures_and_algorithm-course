import java.util.Arrays;
import java.util.HashMap;

class Solution {
    public static void main(String[] args) {
        int[] nums={2, 7, 11, 15};
        int target=9;
        System.out.println(Arrays.toString(twoSum(nums, target)));
    }
    public static int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> storeNums = new HashMap<>(nums.length, 1);
        int[] result = new int[2];
        for (int i=0; i<nums.length;++i){
            int another = target - nums[i];
            Integer anotherIndex = storeNums.get(another);
            if(null!=anotherIndex){
                result[0]=anotherIndex;
                result[1]=i;
                break;
            }else {
                storeNums.put(nums[i],i);
            }
        }
        return result;
    }
}