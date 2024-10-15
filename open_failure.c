/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_failure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-12 08:07:58 by root              #+#    #+#             */
/*   Updated: 2024-10-12 08:07:58 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

// int main()
// {
//     int fd = open("filename.txt",O_RDWR);
//     if ( fd < 0)
//     {
//         printf("---->%d\n",errno);
//         perror("failed to open the file");
//         exit(11);
//     }
//     printf("all is good\n");
//     return(0);

// }

#include <stdio.h>
#include <errno.h>

int main() {
    FILE *file = fopen("nonexistentfile.txt", "r");

    if (file == NULL) {
        // Print the integer value of errno
        printf("Error code (errno): %d\n", errno);  // Prints: 2 (for ENOENT)

        // Check if the error is 'No such file or directory'
        if (errno == ENOENT) {
            printf("Error: No such file or directory (ENOENT)\n");
        }
    }

    return 0;
}
