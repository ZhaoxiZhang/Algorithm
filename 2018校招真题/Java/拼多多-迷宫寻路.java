import java.util.*;

class Node{
    int x;
    int y;
    int status;
    int step;

    public Node(int x, int y, int status, int step){
        this.x = x;
        this.y = y;
        this.status = status;
        this.step = step;
    }
}

public class Main{
    public static final int MASK = 0x1F;
    public static final int SHIFT = 5;

    static char[][] maze;
    static int[][][] vis;
    public static void main(String... args){
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        maze = new char[m + 5][n + 5];
        vis = new int[m + 5][n + 5][35];
        int sx = 0, sy = 0;
        boolean find = false;
        for (int i = 0; i < m; i++){
            maze[i] = scanner.next().toCharArray();
            for (int j = 0; j < n; j++){
                if (find)   break;
                if (maze[i][j] == '2'){
                    find = true;
                    sx = i; sy = j;
                }
            }
        }
        System.out.println(bfs(m, n, sx, sy));
    }

    static boolean isLower(char c){
        return c >= 'a' && c <= 'z';
    }

    static boolean isUpper(char c){
        return c >= 'A' && c <= 'Z';
    }

    static boolean bit_test(int nx, int ny, int status){
        return (vis[nx][ny][status >> SHIFT] & (1 << (status & MASK))) != 0 ? true : false;
    }

    static void bit_set(int nx, int ny, int status){
        vis[nx][ny][status >> SHIFT] |= (1 << (status & MASK));
    }

    static int bfs(int m, int n, int sx, int sy){
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        Queue<Node>queue = new LinkedList<>();
        queue.add(new Node(sx, sy, 0, 0));

        while (!queue.isEmpty()){
            Node top = queue.poll();
            if (maze[top.x][top.y] == '3')  return top.step;

            for (int i = 0; i < 4; i++){
                int nx = top.x + dx[i], ny = top.y + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || maze[nx][ny] == '0')  continue;
                int status = top.status;
                if (isUpper(maze[nx][ny]) && ((status & (1 << (maze[nx][ny] - 'A'))) == 0)) continue;
                if (isLower(maze[nx][ny])){
                    status |= (1 << (maze[nx][ny] - 'a'));
                }

                if (!bit_test(nx, ny, status)){
                    bit_set(nx, ny, status);
                    queue.add(new Node(nx, ny, status, top.step + 1));
                }
            }
        }
        return 0;
    }
}