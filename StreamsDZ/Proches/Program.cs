
using System;

class Proches
{
    static void Main(string[] args)
    {
        Console.WriteLine("Дочерний процесс запущен!");
   
        foreach (var arg in args)
        {
            Thread.Sleep(5000);
            Console.WriteLine($"Получен аргумент: {arg}");
        }
        
        
    }
}
