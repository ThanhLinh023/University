import java.io.File;
import java.io.FileReader;
import java.util.Scanner;
import java.io.IOException;
import java.text.DecimalFormat;
import java.io.FileWriter;
import java.lang.*;

public class bai7 {
    public static void main(String[] args) {
        try {
            DecimalFormat df = new DecimalFormat("0.00");
            int day;
            FileReader inputFile = new FileReader("temperature.txt");
            Scanner input = new Scanner(inputFile);
            day = Integer.parseInt(input.next());
            double[][] temperature = new double[day][12];
            for (int i = 0; i < day; i++) 
            {
                for (int j = 0; j < 12; j++) 
                {
                    temperature[i][j] = Double.parseDouble(input.next());
                }
            }
            inputFile.close();
            double avgTempPerDay[] = new double[day];
            double max[] = new double[day];
            double min[] = new double[day];
            double sumTemp = 0.0;
            double maxTemp = -9999999.0;
            double minTemp = 9999999.0;
            for (int i = 0; i < day; i++)
            {
                double maxItem = -9999999.0;
                double minItem = 9999999.0;
                for (int j = 0; j < 12; j++)
                {
                    if (temperature[i][j] >= maxItem)
                    {
                        maxItem = temperature[i][j];
                        max[i] = maxItem;
                    }
                    if (temperature[i][j] <= minItem)
                    {
                        minItem = temperature[i][j];
                        min[i] = minItem;
                    }
                    if (temperature[i][j] >= maxTemp)
                    {
                        maxTemp = temperature[i][j];
                    }
                    if (temperature[i][j] <= minTemp)
                    {
                        minTemp = temperature[i][j];
                    }
                    avgTempPerDay[i] += temperature[i][j];
                    sumTemp += temperature[i][j];
                }
                avgTempPerDay[i] /= 7;
            }
            File output = new File("output.txt");
            FileWriter out = new FileWriter("output.txt", true);
            for (int i = 0; i < day; i++)
            {
                out.write("Average - Max - Min Temperature of day " + Integer.toString(i + 1) + ": " + String.valueOf(df.format(avgTempPerDay[i])) + " - "+ String.valueOf(df.format(max[i])) + " - "+ String.valueOf(df.format(min[i])) + "\n");
            }
            out.write("Average - Max - Min Temperature of all days: " + String.valueOf(df.format(sumTemp / (7 * 12))) + " - "+ String.valueOf(df.format(maxTemp)) + " - " + String.valueOf(df.format(minTemp)));
            out.close();
        } 
        catch (IOException e) {
            e.printStackTrace();
        }
    }
}
