After the settlement of git and connection to github, we start to play with java.

Open IntelliJ.

# play around with intelliJ

First, create a new project.

![](\Asset\img\Open_IntelliJ.png)

Choose language JAVA, and select JDK.

![](\Asset\img\Open_IntelliJ_2.png)

What ever.

![Open_IntelliJ_Project](\Asset\img\Open_IntelliJ_Project.png)

Continue, continue, then a blank project has been created.

![IntelliJ_Project_Package](\Asset\img\IntelliJ_Project_Package.png)

Here, create a new package.

![IntelliJ_Project_Package_File](\Asset\img\IntelliJ_Project_Package_File.png)

Following create a new file, be a ware of the name.

After created a new file, we can now do the program.

![Java_Start](\Asset\img\Java_Start.png)

In this article, I shall talk about the command line arguments in IntelliJ.

Suppose we have finished the code:

```java
package Package1;
public class Mydemonstration1 {
    public static void main (String[] arg){
        System.out.println(arg[0]);
    }
}
```

Here the argument of main is called program arguments. Normally input are from cmd. But we can apply that in IntelliJ as well.

After ran it:

![IntellJ_program_argument](\Asset\img\IntellJ_program_argument.png)

After run it, configurations is created.

Here:

![](\Asset\img\IntellJ_program_argument2.png)

Apply and run it again.

![IntellJ_program_argument_output](\Asset\img\IntellJ_program_argument_output.png)

It works.

Then we make a few program on intelliJ.

Especially I would like to mention the input/output of java, the variable declaration.

# i/o in Java

Above have I mentioned a method of input in java: use the program arguments. Also, the program showed the output method.

First, the output of java is more varied than C++. Java provides several format for us to output messages.

```java
package Package1;
public class Mydemonstration1 {
    public static void main (String[] arg){
        System.out.print(arg[0]);
        System.out.println(arg[0]);
        System.out.printf(arg[0]);
    }
}

```

The result is like this:

```
Input_arguments_hereInput_arguments_here
Input_arguments_here
```

The method print will not end the line automatically but the println will.

"printf", which means a formatted output, have a strong ability. The following statement describe a few formats.

```
        System.out.printf("Hello Java, %40s"+arg[0],arg[0]);
```

The output is following:

```
Hello Java,                     Input_arguments_hereInput_arguments_here
```

%40s means a string with 40 char width. Align from right side.

But when the integer is smaller than the length of string, noting happens. The print method comes to an end here.

Then we talk about input.

The arguments is basically set as a string array. Within the elements there is not blank. The blank means separate the arguments.

But sometimes we want other format rather than string. We first set the arguments to

```
Input_arg1234563uments_42336here 12342152
```

to examine the function.

```java
package Package1;
public class Mydemonstration1 {
    public static void main (String[] arg){
	    int ap = Integer.parseInt(arg[0]);
        int av = Integer.valueOf(arg[0]);
    }
}
```



This code won't work, with number format errors.

So Java doesn't provide a existing method to transfer the number in a string to integer.

But this does work:

```java
package Package1;
public class Mydemonstration1 {
    public static void main (String[] arg){
        int bp = Integer.parseInt(arg[1]);
        int bv = Integer.valueOf(arg[1]);
        System.out.printf("bp=%10d\nbv=%10d\n",bp,bv);
    }
}
```

 With answer:

```
bp=  12342152
bv=  12342152
```

The float reading is similar.

Next we talk about another method of input.

## object : Scan

The example code is as follow:

```java
package PlaceOrder;

import java.io.InputStream;
import java.util.Scanner;

public class PlaceOrder {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Quantity: ");
        int q = Integer.parseInt(scan.next());
        scan.nextLine();
        System.out.print("Description: ");
        String d = scan.nextLine();

        System.out.print("Unit Price: ");
        double t = scan.nextDouble();

        System.out.printf("Order for %d %s\n",q,d.toUpperCase());
        System.out.printf("Total Price%14.2f",t*(double) q);
    }
}
```

Which means in java we should declare a object that is Scanner, then we can get into input.

First import the scanner outside the class.

```java
import java.util.Scanner;
```



Declaration statement:

```java
Scanner thescannernamehere = new Scanner(System.in);
```

Java also provided several format of reading:

```java
scan.next();
scan.nextLine();
scan.nextDouble();
scan.nextInt();
```

They are similar, but be aware of the scan.next() statement : 

It reads until the next blank, or endline mark. But it may not read the mark in.

Which means if we use .next() reads till the end of the line, if we want to use .nextLine() next, we should first read the endline mark in.

Or else, the .nextLine() will read the endline mark this line and end!

# Euler Prime Algorithm

I coded a Euler Prime algorithm in java:

```java
package Primes;

import java.sql.Array;

public class Primes {
    public static void main (String[] args) {
        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);
        int[] p = new int[6465412];
        boolean[] v = new boolean[b+1];
        int cnt = 0;
        for(int i=0;i<=b;i++)
            v[i] = false;
        int i=2;
        for(i=2;i<=b;i++)
        {
            if(!v[i])
            {

                p[cnt] = i ;
                cnt++;
                v[i] = true;
            }
            for(int j=0;j<cnt;j++)
            {
                if(i*p[j]>b)
                {
                    break;
                }
                v[i*p[j]]= true;
                int tmp = i %(p[j]);
                if(tmp==0)
                    break;
            }
        }


        for( i=0;i<cnt;i++) {
            if(p[i]>=a && p[i]<=b)
            {
                System.out.println(p[i]);
            }
        }
    }
}
```

