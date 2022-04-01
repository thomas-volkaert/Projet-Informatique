import java.util.ArrayList;
import java.util.Random;

public class Rabbit 
{
    public int      ageMois,diff;
    public String   genre;
    public boolean  adult,life,fertile;
    public float    survie;
    public MTwister x_random;
    public double   age_random,genre_random,death_random,fertile_random,birth_random;
    
    public Rabbit () 
    {
        this.ageMois = 0;
        this.life    = true;
        this.survie  = (float) 0.75;
        this.fertile = true;
        this.adult   = false;
    }
   

    public Rabbit (int ageMois, String genre, boolean adult) 
    {
        this.ageMois = ageMois;
        this.genre   = genre;
        this.adult   = adult;
        this.life    = true;
        this.survie  = (float) 0.75;
        this.fertile = true;
    }

    public void verifGenre(double x_random)
    {
        if (x_random <= 0.5 )
        {
            this.genre = "femelle";
        }
        else
        {
            this.genre = "male";
        }
    }


    public void fertilite(double x_random)
    {
        if(this.genre == "femelle")
        {
            if(x_random <= 0.10)
            {
                this.fertile = false;
            } 
        }
    }


    public void verifMaturite(double x_random) // babytoadult
    {
       if(ageMois >= 5 && ageMois < 8)
       { 
            if (x_random <= 0.5 )
            {
                this.adult = true;
            }
        }
        else if (ageMois >= 8)
        {
            this.adult = true;
        }
        else 
        {
            this.adult = false;
        }
    }


    public void survieAge()
    {
        if(this.ageMois >= 84)
        { 
            this.survie -= 0.15;
        }
    }


    public void verifDeath(double x_random)
    {
        //survie adulte
        if(this.adult == true)
        { 
            if(x_random > this.survie)
            {
                this.life = false;
            }
        }
        //survie enfant
        if(this.adult == false)
        { 
            if(x_random > 0.5)
            {
                this.life = false;
            }
        }
        //survie femelle
        if(this.genre == "femelle")
        { 
            if(x_random < 0.15)
            {
                this.life = false;
            }
        }
    }


    public int naissance(double x_random)
    {
        if(this.genre == "femelle" && this.fertile != false && this.adult == true)
        { 
            if(x_random < 1/16)
            {
                return 3;
            }
            else if (x_random < 3/16)
            {
                return 4;
            }
            else if (x_random < 6/16)
            {
                return 5;
            }
            else if (x_random < 10/16)
            {
                return 6;
            }
            else if (x_random < 13/16)
            {
                return 7;
            }
            else if (x_random < 15/16)
            {
                return 8;
            }
            else
            {
                return 9;
            }
        }
        else
        {
            return 0;
        }
    }
    

    public String toString()
    {
        return  ageMois + " " + genre + " " + adult + " " + life + " " + fertile + " " + survie;
    }

    public static void fibonacci(int MAX)
    {
        int i,temp,
            adultRabbit = 0,
            youngRabbit = 2;
        System.out.printf("Nombres de couples le mois 0 : 1 \n");
        for(i = 0; i < MAX + 1; i++)
        {
            temp = youngRabbit;
            youngRabbit += adultRabbit;
            adultRabbit += temp;
            youngRabbit -= temp;
            System.out.printf("Nombres de couples le mois %d : %d\n",i + 1,(adultRabbit + youngRabbit)/2 );
        }
    }

    
    



    public static void main(String [] args) 
    {
        int                 i;
        int                 nbNaissance = 0;
        int                 nb          = 0;
        long[]              init        = {0x123, 0x234, 0x345, 0x456};
        MTwister            x_random    = new MTwister();
        ArrayList<Rabbit>   population  = new ArrayList<Rabbit>();
        Rabbit              a           = new Rabbit(10,"femelle",true);
        Rabbit              b           = new Rabbit(10,"male",true);

        population.add(a);
        population.add(b);
        x_random.init_by_array(init);

        //Rabbit c = new Rabbit();
        //c.verifGenre();

        //System.out.println(c);
        
        for (i = 0; i < 24; i++)
        {
            for (int j = 0; j < population.size(); j++)
            {
                nbNaissance = (population.get(j)).naissance(x_random.genrand_real1());
                nb += nbNaissance;
                System.out.println(nbNaissance);
            }

            for (int k = 0 ; k < nb; k++)
            {
                Rabbit r = new Rabbit();
                r.verifGenre(x_random.genrand_real1()); 
                r.fertilite(x_random.genrand_real1());
                population.add(r);
            }
            
            for (int agee = 0 ; agee < population.size(); agee++)
            {
                population.get(agee).ageMois++;
                population.get(agee).verifDeath(x_random.genrand_real1());
                population.get(agee).verifMaturite(x_random.genrand_real1());
            } 
            System.out.println("-----" + i);
            
            nb = 0;

        }

        System.out.println(population.size());
        
    }
}
