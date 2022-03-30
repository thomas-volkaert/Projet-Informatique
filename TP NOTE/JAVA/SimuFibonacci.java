public class SimuFibonacci{

    public static void fibonacci(int MAX)
    {
        int i,temp,
            adultRabbit = 0,
            youngRabbit = 2;
        System.out.printf("Nombres de couples le mois 0 : 1 \n");
        for(i = 0; i<MAX+1; i++)
        {
            temp = youngRabbit;
            youngRabbit += adultRabbit;
            adultRabbit += temp;
            youngRabbit -= temp;
            System.out.printf("Nombres de couples le mois %d : %d\n",i+1,(adultRabbit+youngRabbit)/2);
        }
    }
}