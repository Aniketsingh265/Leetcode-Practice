class Solution {
    public String reverseWords(String s) {
        // ArrayList<String> arr = new ArrayList<>();
        String[] ch = s.trim().split("\\s+");
        for(String a : ch){
             System.out.println(a);
        }
        int start = 0;
        int end = ch.length -1; 

        while(start<end){
            String temp = ch[start];
            ch[start] = ch[end];
            ch[end] = temp;

            start++;
            end--;
        }
        for(var it : ch){
            it = it.trim();
        }
        return String.join(" ",ch);
    }
}