#!/bin/bash

mysql_install_db --user=mysql --datadir=/var/lib/mysql
mysqld --user=mysql --datadir=/var/lib/mysql --skip-networking &

while ! mysqladmin ping --silent; do
    sleep 1
done

mysql -uroot -p"$MYSQL_ROOT_PASSWORD" << EOF
CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;
EOF

mysqladmin shutdown

exec "$@"

# #!/bin/sh

# if [ ! -d "/var/lib/mysql/mysql" ]; then
#     echo "Initializing MariaDB data directory"
#     mysql_install_db --user=mysql --datadir=/var/lib/mysql
# fi

# # Start MariaDB server in the background
# mysqld --user=mysql --datadir=/var/lib/mysql --skip-networking &
# pid="$!"

# # Wait for the MariaDB server to start
# while ! mysqladmin ping --silent; do
#     sleep 1
# done

# # Run the SQL script to create the database
# if [ -f /etc/mysql/init.sql ]; then
#     echo "Initializing database"
#     mysql -uroot < /etc/mysql/init.sql
#     echo "Database initialized"
# fi

# # Stop the MariaDB server
# mysqladmin shutdown

# # Execute CMD
# exec "$@"
