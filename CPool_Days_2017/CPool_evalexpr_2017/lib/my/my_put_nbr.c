/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

int	my_put_nbr(int nb)
{
  long int	i;

  i = nb;
  if (i < 0)
    {
      my_putchar('-');
      i = i * -1;
    }
  if (i >= 10)
    {
      my_put_nbr(i / 10);
    }
  i = i % 10 + '0';
  my_putchar(i);
}
