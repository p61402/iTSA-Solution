import java.util.*;

public class Main {
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		int num = 0;
		num = input.nextInt();
		while(num > 0)
		{
			int num_people = input.nextInt();
			int sum = 0;
			int[] skill=new int[num_people];
			for(int i=0; i<num_people; i++)
			{
				int power = input.nextInt();
				int weight = input.nextInt();
				skill[i] = power/weight;
				sum += skill[i];
			}
			
			int[] dp = new int[sum+1];
			boolean[][] p = new boolean[num_people][sum+1];
			
			for(int i=0; i<num_people; i++)
				for(int j=0; j<=sum; j++)
					p[i][j] = false;
			
			for(int i=0; i<num_people; i++)
				dp[i] = 0;
					
			for(int i=0; i<num_people; i++)
			{
				for(int j=sum; j-skill[i]>=0; j--)
				{
					if(dp[j-skill[i]]+skill[i] > dp[j])
					{
						dp[j] = dp[j-skill[i]]+skill[i];
						p[i][j] = true;
					}
				}
			}

			int min_index = sum/2;
			int min_difference = sum - 2 * dp[sum/2];
			for(int i=sum/2; i<=sum; i++)
			{
				if(Math.abs(sum - 2 * dp[i]) <= min_difference)
				{
					min_difference = Math.abs(sum - 2 * dp[i]);
					min_index = i;
				}
				else
				{
					break;
				}
			}
			
			System.out.println(min_difference);
			
			int number_of_items = 0;
			for(int i=num_people-1, j=min_index; i>=0; i--)
			{
				if(p[i][j])
				{
					number_of_items += 1;
					j -= skill[i];
				}
			}

			if(num_people - number_of_items >= num_people / 2)
			{
				System.out.println(number_of_items);
			}
			else
			{
				System.out.println(num_people - number_of_items);
			}
			
			num--;
		}
	}

}
