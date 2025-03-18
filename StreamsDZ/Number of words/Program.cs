
string[] word = args[0].Split('\\');

int count = 0;
foreach (string i in word)
{
    if (i == args[1])
    {
        count++;
    }
}
Console.WriteLine(count);




