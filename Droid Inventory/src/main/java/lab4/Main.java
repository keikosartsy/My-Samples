package lab4;
import java.util.*;
import java.io.*;
import java.util.regex.*;

/**
 * @author Kayla Okazaki & Carina dePillis-Shintaku
 */

public class Main {
    //find all vaild droid listings & stores in array
    public static void findDroids(String[][] droid)
    {
        try 
        {
            //create scanner for droids_in.txt file
            Scanner input = new Scanner(new File("droids_in.txt"));
            
            //holds the current line in file
            String line;
            
            //ints for array indexs
            int i = 0;
            int j = 0;
            
            //holds the different patterns for droid names
            Pattern RX = Pattern.compile("R[2-5](-?)[A-Z][0-9]([0-9]?)");
            Pattern P2 = Pattern.compile("P2(-?)[A-Z]\\d");
            Pattern BB = Pattern.compile("BB-[0-9]([A-Z]?)(\\d?)");
            Pattern _3PO = Pattern.compile("[A-Z](\\d?)-3PO");
            Pattern TC = Pattern.compile("TC-\\d{2}");
            Pattern IG = Pattern.compile("IG-[A-Z\\d]{2}");
            
            //holds the pattern for price
            Pattern price_start = Pattern.compile(">");
            Pattern price = Pattern.compile("(\\d{3,5}(\\.\\d{2})?)");
             
            //loops through lines of file until it reaches the end
            while(input.hasNext())
            {            
                //gets the next line
                line = input.nextLine();
                
                //creates matcher for droid names & prices
                Matcher RX_match = RX.matcher(line);
                Matcher P2_match = P2.matcher(line);
                Matcher BB_match = BB.matcher(line);
                Matcher _3PO_match = _3PO.matcher(line);
                Matcher TC_match = TC.matcher(line);
                Matcher IG_match = IG.matcher(line);
                Matcher price_start_match = price_start.matcher(line);
                Matcher price_match = price.matcher(line);
                
                //finds all droids in the R series 
                while(RX_match.find())
                {
                    //looks for > character after the end of the droid's name
                    if(price_start_match.find(RX_match.end()))
                    {
                        //looks for valid price & prints the droid's name and price into droid array
                       if(price_match.find(price_start_match.end()))
                       {
                           droid[i][j] = RX_match.group();
                           droid[i][j+1] = price_match.group();
                           i++;
                       }
                    }
                }
                //finds all droids in the P2 series
                while(P2_match.find())
                {
                    //looks for > character after the end of the droid's name
                    if(price_start_match.find(P2_match.end()))
                    {
                        //looks for valid price & prints the droid's name and price into droid array
                       if(price_match.find(price_start_match.end()))
                       {
                           droid[i][j] = P2_match.group();
                           droid[i][j+1] = price_match.group();
                           i++;
                       }
                    }
                }
                //finds all droids in the BB series
                while(BB_match.find())
                {
                    //looks for > character after the end of the droid's name
                    if(price_start_match.find(BB_match.end()))
                    {
                        //looks for valid price & prints the droid's name and price into droid array
                       if(price_match.find(price_start_match.end()))
                       {
                           droid[i][j] = BB_match.group();
                           droid[i][j+1] = price_match.group();
                           i++;
                       }
                    }
                }
                //finds all droids in the 3PO series
                while(_3PO_match.find())
                {
                    //looks for > character after the end of the droid's name
                    if(price_start_match.find(_3PO_match.end()))
                    {
                        //looks for valid price & prints the droid's name and price into droid array
                       if(price_match.find(price_start_match.end()))
                       {
                           droid[i][j] = _3PO_match.group();
                           droid[i][j+1] = price_match.group();
                           i++;
                       }
                    }
                }
                //finds all droids in the TC series
                while(TC_match.find())
                {
                    //looks for > character after the end of the droid's name
                    if(price_start_match.find(TC_match.end()))
                    {
                        //looks for valid price & prints the droid's name and price into droid array
                       if(price_match.find(price_start_match.end()))
                       {
                           droid[i][j] = TC_match.group();
                           droid[i][j+1] = price_match.group();
                           i++;
                       }
                    }
                }
                //finds all droids in the IG series
                while(IG_match.find())
                {
                    //looks for > character after the end of the droid's name
                    if(price_start_match.find(IG_match.end()))
                    {
                        //looks for valid price & prints the droid's name and price into droid array
                       if(price_match.find(price_start_match.end()))
                       {
                           droid[i][j] = IG_match.group();
                           droid[i][j+1] = price_match.group();
                           i++;
                       }
                    }
                }   
            }
        } 
        catch (FileNotFoundException e) 
        {
            System.out.println("There was an error trying to open input file.");
        }
    }
    
    //sorts each droid from array into series specific droids & prints them to output file after sorting
    public static void sortAndPrintDroids(String[][] droid)
    {
        final int ROWS = 40;
        final int COLUMNS = 2;
        try 
        { 
            //create PrintWriter to write droids & price to droids_out.txt
            PrintWriter output = new PrintWriter("droids_out.txt");
            
            //arrays to hold different droids to print to droids_out.txt
            String[][] R2_droids = new String[ROWS][COLUMNS];
            String[][] R3_droids = new String[ROWS][COLUMNS];
            String[][] R4_droids = new String[ROWS][COLUMNS];
            String[][] R4P_droids = new String[ROWS][COLUMNS];
            String[][] R5_droids = new String[ROWS][COLUMNS];
            String[][] P2_droids = new String[ROWS][COLUMNS];
            String[][] BB_droids = new String[ROWS][COLUMNS];
            String[][] _3PO_droids = new String[ROWS][COLUMNS];
            String[][] TC_droids = new String[ROWS][COLUMNS];
            String[][] IG_droids = new String[ROWS][COLUMNS];
            
            //regex patterns to find droids
            Pattern R2 = Pattern.compile("R2(-?)[A-Z]\\d");
            Pattern R3 = Pattern.compile("R3(-?)[A-Z]\\d");
            Pattern R4 = Pattern.compile("R4(-?)[A-Z]\\d");
            Pattern R4P = Pattern.compile("R4-P[0-9]\\d");
            Pattern R5 = Pattern.compile("R5(-?)[A-Z]\\d");
            Pattern P2 = Pattern.compile("P2(-?)[A-Z]\\d");
            Pattern BB = Pattern.compile("BB-\\d([A-Z]?)(\\d?)");
            Pattern _3PO = Pattern.compile("[A-Z](\\d?)-3PO");
            Pattern TC = Pattern.compile("TC-\\d{2}");
            
            
            //ints to hold total number of each droids
            int r2Droids = 0;
            int r3Droids = 0;
            int r4Droids = 0;
            int r4PDroids = 0;
            int r5Droids = 0;
            int p2Droids = 0;
            int bbDroids = 0;
            int _3poDroids = 0;
            int tcDroids = 0;
            int igDroids = 0;
            
            
            //int for array index
            int j = 0;
            
            //loops through droid array to store them into the appropriate arrays
            for(int i = 0; i < droid.length; i++)
            {
                //breaks out of loop if there are no more droids to add to the arrays
                if(null == droid[i][j])
                   {break;}
                else
                {
                    //strings to hold droid name & prices to add to arrays
                    String line = droid[i][j];
                    String priceLine = droid[i][j+1];
                    
                    //creating matchers for patterns
                    Matcher R2_match = R2.matcher(line);
                    Matcher R3_match = R3.matcher(line);
                    Matcher R4_match = R4.matcher(line);
                    Matcher R4P_match = R4P.matcher(line);
                    Matcher R5_match = R5.matcher(line);
                    Matcher P2_match = P2.matcher(line);
                    Matcher BB_match = BB.matcher(line);
                    Matcher _3PO_match = _3PO.matcher(line);
                    Matcher TC_match = TC.matcher(line);
                    
                    //droid is a R2 series & is stored in the R2 array. Update R2 counter
                    if(R2_match.find())
                    {
                        R2_droids[i][j] = line;
                        R2_droids[i][j+1] = priceLine;
                        r2Droids++;
                    }
                    //droid is a R3 series & is stored in the R3 array. Update R3 counter
                    else if(R3_match.find())
                    {
                        R3_droids[i][j] = line;
                        R3_droids[i][j+1] = priceLine;
                        r3Droids++;
                    }
                    else if(R4_match.find())
                    {
                        //droid is a R4P series & is stored in the R4P array. Update R4P counter
                       if(R4P_match.find())
                       {
                           R4P_droids[i][j] = line;
                           R4P_droids[i][j+1] = priceLine;
                           r4PDroids++;
                       }
                       //droid is a R4 series & is stored in the R4 array. Update R4 counter
                       else
                       {
                           R4_droids[i][j] = line;
                           R4_droids[i][j+1] = priceLine;
                           r4Droids++;
                       }
                    }
                    //droid is a R5 series & is stored in the R5 array. Update R5 counter
                    else if(R5_match.find())
                    {
                        R5_droids[i][j] = line;
                        R5_droids[i][j+1] = priceLine;
                        r5Droids++;
                    }
                    //droid is a P2 series & is stored in the P2 array. Update P2 counter
                    else if(P2_match.find())
                    {
                        P2_droids[i][j] = line;
                        P2_droids[i][j+1] = priceLine;
                        p2Droids++;
                    }
                    //droid is a BB series & is stored in the BB array. Update BB counter
                    else if(BB_match.find())
                    {
                        BB_droids[i][j] = line;
                        BB_droids[i][j+1] = priceLine;
                        bbDroids++;
                    }
                    //droid is a 3PO series & is stored in the 3PO array. Update 3PO counter
                    else if(_3PO_match.find())
                    {
                        _3PO_droids[i][j] = line;
                        _3PO_droids[i][j+1] = priceLine;
                        _3poDroids++;
                    }
                    //droid is a TC series & is stored in the TC array. Update TC counter
                    else if(TC_match.find())
                    {
                        TC_droids[i][j] = line;
                        TC_droids[i][j+1] = priceLine;
                        tcDroids++;
                    }
                    //droid is a IG series & is stored in the IG array. Update IG counter
                    else
                    {
                        IG_droids[i][j] = line;
                        IG_droids[i][j+1] = priceLine; 
                        igDroids++;
                    }
                }
            } 
            //sorts array from lowest price to highest price
            arraySort(R2_droids);
            arraySort(R3_droids);
            arraySort(R4_droids);
            arraySort(R4P_droids);
            arraySort(R5_droids);
            arraySort(P2_droids);
            arraySort(BB_droids);
            arraySort(_3PO_droids);
            arraySort(TC_droids);
            arraySort(IG_droids);
            
            //print header for R2 droids
            output.println("*****************************");
            output.println("* R2 Units                  *");
            output.println("*****************************");
            
            if(r2Droids > 0)
            {
                //prints total number of R2 droids available
                output.println(r2Droids + " R2 units available");
                output.println(" ");
                
                //prints lists of R2 droids & prices
                output.println("--Name------------Price-----");
                for(int i = 0; i < R2_droids.length; i++)
                {
                    if(null != R2_droids[i][j])
                    {
                        //changes length of space between name and price based on length of name for consistant format
                        if(R2_droids[i][j].length() == 5)
                        {
                            output.printf("%s             %.2f Cr\n", R2_droids[i][j],Double.parseDouble(R2_droids[i][j+1]));
                        }
                        else
                        {
                            output.printf("%s              %.2f Cr\n", R2_droids[i][j],Double.parseDouble(R2_droids[i][j+1]));
                        }
                    }
                }
                output.println("----------------------------");
                output.println(" ");
            }
            else
            {
                output.println("0 R2 units available");
                output.println(" ");
            }
            
            output.println("*****************************");
            output.println("* R3 Units                  *");
            output.println("*****************************");
            
            if(r3Droids > 0)
            {
                //prints total number of R3 droids available
                output.println(r3Droids + " R3 units available");
                output.println(" ");
                
                //prints lists of R3 droids & prices
                output.println("--Name------------Price-----");
                for(int i = 0; i < R3_droids.length; i++)
                {
                    if(null != R3_droids[i][j])
                    {
                        //changes length of space between name and price based on length of name for consistant format
                        if(R3_droids[i][j].length() == 5)
                        {
                            output.printf("%s             %.2f Cr\n", R3_droids[i][j],Double.parseDouble(R3_droids[i][j+1]));
                        }
                        else
                        {
                            output.printf("%s              %.2f Cr\n", R3_droids[i][j],Double.parseDouble(R3_droids[i][j+1]));
                        }
                        
                    }
                }
                output.println("----------------------------");
                output.println(" ");
            }
            else
            {
                output.println("0 R3 units available");
                output.println(" ");
            }
            
            output.println("*****************************");
            output.println("* R4 Units                  *");
            output.println("*****************************");
            
            if(r4Droids > 0)
            {
                //prints total number of R4 droids available
                output.println(r4Droids + " R4 units available");
                output.println(" ");
                
                //prints lists of R4 droids & prices
                output.println("--Name------------Price-----");
                for(int i = 0; i < R4_droids.length; i++)
                {
                    if(null != R4_droids[i][j])
                    {
                        //changes length of space between name and price based on length of name for consistant format
                        if(R4_droids[i][j].length() == 5)
                        {
                            output.printf("%s             %.2f Cr\n", R4_droids[i][j],Double.parseDouble(R4_droids[i][j+1]));
                        }
                        else
                        {
                            output.printf("%s              %.2f Cr\n", R4_droids[i][j],Double.parseDouble(R4_droids[i][j+1]));
                        }
                    }
                }
                output.println("----------------------------");
                output.println(" ");
            }
            else
            {
                output.println("0 R4 units available");
                output.println(" ");
            }
            
            output.println("*****************************");
            output.println("* R4-P Units                *");
            output.println("*****************************");
            
            if(r4PDroids > 0)
            {
                //prints total number of R4P droids available
                output.println(r4PDroids + " R4-P units available");
                output.println(" ");
                
                //prints lists of R4P droids & prices
                output.println("--Name------------Price-----");
                for(int i = 0; i < R4P_droids.length; i++)
                {
                    if(null != R4P_droids[i][j])
                    {
                        output.printf("%s            %.2f Cr\n", R4P_droids[i][j],Double.parseDouble(R4P_droids[i][j+1]));
                    }
                }
                output.println("----------------------------");
                output.println(" ");
            }
            else
            {
                output.println("0 R4-P units available");
                output.println(" ");
            }
            
            output.println("*****************************");
            output.println("* R5 Units                  *");
            output.println("*****************************");
            
            if(r5Droids > 0)
            {
                //prints total number of R5 droids available
                output.println(r5Droids + " R5 units available");
                output.println(" ");
                
                //prints lists of R5 droids & prices
                output.println("--Name------------Price-----");
                for(int i = 0; i < R5_droids.length; i++)
                {
                    if(null != R5_droids[i][j])
                    {
                        //changes length of space between name and price based on length of name for consistant format
                        if(R5_droids[i][j].length() == 5)
                        {
                            output.printf("%s             %.2f Cr\n", R5_droids[i][j],Double.parseDouble(R5_droids[i][j+1]));
                        }
                        else
                        {
                            output.printf("%s              %.2f Cr\n", R5_droids[i][j],Double.parseDouble(R5_droids[i][j+1]));
                        }
                    }
                }
                output.println("----------------------------");
                output.println(" ");
            }
            else
            {
                output.println("0 R5 units available");
                output.println(" ");
            }
            
            output.println("*****************************");
            output.println("* P2 Units                  *");
            output.println("*****************************");
            
            if(p2Droids > 0)
            {
                //prints total number of P2 droids available
                output.println(p2Droids + " P2 units available");
                output.println(" ");
                
                //prints lists of P droids & prices
                output.println("--Name------------Price-----");
                for(int i = 0; i < P2_droids.length; i++)
                {
                    if(null != P2_droids[i][j])
                    {
                        //changes length of space between name and price based on length of name for consistant format
                        if(P2_droids[i][j].length() == 5)
                        {
                            output.printf("%s             %.2f Cr\n", P2_droids[i][j],Double.parseDouble(P2_droids[i][j+1]));
                        }
                        else
                        {
                            output.printf("%s              %.2f Cr\n", P2_droids[i][j],Double.parseDouble(P2_droids[i][j+1]));
                        }
                    }
                }
                output.println("----------------------------");
                output.println(" ");
            }
            else
            {
                output.println("0 P2 units available");
                output.println(" ");
            }
            
            output.println("*****************************");
            output.println("* BB Units                  *");
            output.println("*****************************");
            
             if(bbDroids > 0)
            {
                //prints total number of BB droids available
                output.println(bbDroids + " BB units available");
                output.println(" ");
                
                //prints lists of BB droids & prices
                output.println("--Name------------Price-----");
                for(int i = 0; i < BB_droids.length; i++)
                {
                    if(null != BB_droids[i][j])
                    {
                        //changes length of space between name and price based on length of name for consistant format
                        switch (BB_droids[i][j].length()) {
                            case 5:
                                output.printf("%s             %.2f Cr\n", BB_droids[i][j],Double.parseDouble(BB_droids[i][j+1]));
                                break;
                            case 6:
                                output.printf("%s            %.2f Cr\n", BB_droids[i][j],Double.parseDouble(BB_droids[i][j+1]));
                                break;
                            default:
                                output.printf("%s              %.2f Cr\n", BB_droids[i][j],Double.parseDouble(BB_droids[i][j+1]));
                                break;
                        }
                    }
                }
                output.println("----------------------------");
                output.println(" ");
            }
            else
            {
                output.println("0 BB units available");
                output.println(" ");
            }
            
            output.println("*****************************");
            output.println("* 3PO Units                 *");
            output.println("*****************************");
            
            if(_3poDroids > 0)
            {
                //prints total number of 3PO droids available
                output.println(_3poDroids + " 3PO units available");
                output.println(" ");
                
                //prints lists of 3PO droids & prices
                output.println("--Name------------Price-----");
                for(int i = 0; i < _3PO_droids.length; i++)
                {
                    if(null != _3PO_droids[i][j])
                    {
                        //changes length of space between name and price based on length of name for consistant format
                        if(_3PO_droids[i][j].length() == 6)
                        {
                            output.printf("%s            %.2f Cr\n", _3PO_droids[i][j],Double.parseDouble(_3PO_droids[i][j+1]));
                        }
                        else
                        {
                            output.printf("%s             %.2f Cr\n", _3PO_droids[i][j],Double.parseDouble(_3PO_droids[i][j+1]));
                        }
                    }
                }
                output.println("----------------------------");
                output.println(" ");
            }
            else
            {
                output.println("0 3PO units available");
                output.println(" ");
            }
            
            output.println("*****************************");
            output.println("* TC Units                  *");
            output.println("*****************************");
            
            if(tcDroids > 0)
            {
                //prints total number of TC droids available
                output.println(tcDroids + " TC units available");
                output.println(" ");
                
                //prints lists of TC droids & prices
                output.println("--Name------------Price-----");
                for(int i = 0; i < TC_droids.length; i++)
                {
                    if(null != TC_droids[i][j])
                    {
                        output.printf("%s             %.2f Cr\n", TC_droids[i][j],Double.parseDouble(TC_droids[i][j+1]));
                    }
                }
                output.println("----------------------------");
                output.println(" ");
            }
            else
            {
                output.println("0 TC units available");
                output.println(" ");
            }
            
            output.println("*****************************");
            output.println("* IG Units                  *");
            output.println("*****************************");
            
            if(igDroids > 0)
            {
                //prints total number of IG droids available
                output.println(igDroids + " IG units available");
                output.println(" ");
                
                //prints lists of IG droids & prices
                output.println("--Name------------Price-----");
                for(int i = 0; i < IG_droids.length; i++)
                {
                    if(null != IG_droids[i][j])
                    {
                        output.printf("%s             %.2f Cr\n", IG_droids[i][j],Double.parseDouble(IG_droids[i][j+1]));
                    }
                }
                output.println("----------------------------");
                output.println(" ");
            }
            else
            {
                output.println("0 IG units available");
                output.println(" ");
            }  
            
            output.close();
        } 
        catch (FileNotFoundException e) 
        {
            System.out.println("There was an error trying to open output file.");
        }  
    }
    
    //sorts arrays in ascending price order before the array is printed to output file
    public static void arraySort(String[][] droid)
    {
        //array index
        int j = 1;
        
        //loops through the array
        for (int i = 0; i < droid.length; i++)
        {
            if(null != droid[i][j])
            {
                //holds location of current min value
                int droidNameMin = i;
                
                //loops through array values after the current array values
                for(int inner = i+1; inner < droid.length; inner++)
                {
                    //checks if next line is null
                    if(null != droid[inner][j])
                    {
                        //update the minimum value location if new location is found
                        if(Double.parseDouble(droid[inner][j]) < Double.parseDouble(droid[droidNameMin][j]))
                        {
                            droidNameMin = inner;
                        }
                    }   
                }
                
                //swaps the droids if new minimum price if found
                if(droidNameMin != i)
                {
                    String tempName = droid[i][j-1];
                    String tempPrice = droid[i][j];

                    droid[i][j-1] = droid[droidNameMin][j-1];
                    droid[i][j] = droid[droidNameMin][j];

                    droid[droidNameMin][j-1] = tempName;
                    droid[droidNameMin][j] = tempPrice;
                }
            }
        }
        
        
    }

    public static void main(String[] args) {
        final int ROWS = 40;
        final int COLUMNS = 2;
        //2D array to store droid data
        String[][] droid = new String[ROWS][COLUMNS];
        
        //calls funtion to read droids & their prices from input file & stores them in array
        findDroids(droid);
        
        //calls function that will sort & print the droids to output file       
        sortAndPrintDroids(droid);
    }
}
