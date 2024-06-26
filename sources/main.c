int	main (int argc, char **argv)
{
  int		ret;

  ret = 0;
  if (argc == 1)
	{
	  my_putstr("Usage: ./my_ls [-lRdrt] [file ...]\n");
	  return (0);
	}
  ret = my_ls(argc, argv);
  return (ret);
}
