/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:07:35 by fel-aziz          #+#    #+#             */
/*   Updated: 2024/09/20 11:49:18 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <fcntl.h>

// int main()
// {
// 	int j = 0 ;
// 	char buff[12];
// 	int fd = open("oldfil.txt", O_RDWR);
// 	if (fd < 0 )
// 		return(printf("errroor\n"));
// 	dup2(fd,0);
// 	j = read(0, buff, 11);
// 	if (j < 0 )
// 		return(printf("errroor2222\n"));
// 	printf("%s\n",buff);
// 	return(0);
// }

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    // Open a temporary file
    int fd = open("/tmp/tmpfile.txt", O_RDWR | O_CREAT, 0666);


    if (fd == -1) {
        perror("Failed to open temporary file");
        return EXIT_FAILURE;
    }
    const char *data = "Hello, this is a temporary file.\n";
    write(fd, data, strlen(data));
    close(fd);

    printf("Temporary file created successfully.\n");
    return EXIT_SUCCESS;
}
