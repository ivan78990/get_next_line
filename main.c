int main(void)
{
	int   fd;
	char  *line;
	int   ret_get;
	ret_get = 1;
	fd = open("text_file.txt", O_RDONLY);
	while ((ret_get))
	{
		ret_get = get_next_line(fd, &line);
		printf("[%d]\t%s\n", ret_get, line);
		free(line);
	}
	return (0);
}