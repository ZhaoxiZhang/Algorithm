class Solution {
    public void rotate(int[][] matrix) {
        int length = matrix.length;
        int size = matrix[0].length;
        
        //swap column
        for (int i = 0; i < length / 2; i++){
            for (int j = 0; j < size; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[length - i - 1][j];
                matrix[length - i - 1][j] = tmp;
            }
        }

        //swap the symmetry 
        for (int i = 0; i < length; i++){
            for (int j = 0; j < i; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }

    }
}