# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarras <micarras@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/05 17:15:03 by micarras          #+#    #+#              #
#    Updated: 2020/02/06 17:22:35 by micarras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM    debian:buster

LABEL   maintainer="Michael Carrasco <micarras@student.42.fr>"

ARG     DB_ROOT_PASSWORD="root"
ARG     DB_WP_PASSWORD="password"
ARG     WP_ADMIN_PASSWORD="admin"

RUN     apt-get -qq update && apt-get -qq upgrade -y && apt-get -qq install -y \
        openssl nginx systemd default-mysql-server php-fpm php-mysql php-mbstring \
        php-zip php-gd uuid-runtime php-curl php-xml php-xmlrpc php-soap \
        php-intl \
        sudo > /dev/null && rm -rf /var/lib/ap/lists/*

COPY    srcs/localhost /etc/nginx/sites-available/
COPY    srcs/phpMyAdmin-4.9.4.tar.gz srcs/wordpress-5.3.2-fr_FR.tar.gz srcs/wp-cli.phar /tmp/
COPY    srcs/self-signed.conf srcs/ssl-params.conf /etc/nginx/snippets/

RUN     sudo tar xf /tmp/phpMyAdmin-4.9.4.tar.gz -C /usr/share && \
        sudo tar xf /tmp/wordpress-5.3.2-fr_FR.tar.gz -C /usr/share && \
        sudo mkdir /usr/share/phpmyadmin && \
        sudo mv /usr/share/phpMyAdmin*/* /usr/share/phpmyadmin && \
        sudo mv /tmp/wp-cli.phar /usr/local/bin/wp && \
        sudo mkdir /etc/phpmyadmin && \
        sudo chown -R www-data:www-data /usr/share/phpmyadmin && \
        sudo chown -R www-data:www-data /usr/share/wordpress && \
        sudo chmod +x /usr/local/bin/wp && \
        sudo ln -s /usr/share/phpmyadmin /var/www/html/phpmyadmin && \
        sudo ln -s /usr/share/wordpress /var/www/html/wordpress && \
        sudo rm -f /var/www/html/index.nginx*.html /tmp/*

RUN     openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
        -subj "/C=FR/ST=Île-de-France/L=Paris/O=42/CN=42.fr" \
        -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt && \
        openssl dhparam -dsaparam -out /etc/nginx/dhparam.pem 2048 && \
        rm -f /etc/nginx/sites-enabled/default && \
        ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/default && \
        cat -e /etc/ssl/certs/nginx-selfsigned.crt

RUN		service mysql start && \
		mysql -e \
		"UPDATE mysql.user SET Password=PASSWORD('${DB_ROOT_PASSWORD}') WHERE User='root'; \
		DELETE FROM mysql.user WHERE User=''; \
		DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1'); \
		DROP DATABASE IF EXISTS test; \
		DELETE FROM mysql.db WHERE Db='test' OR Db='test\\_%'; \
		FLUSH PRIVILEGES; \
		CREATE DATABASE wordpress DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci; \
		GRANT ALL ON wordpress.* TO 'wp'@'localhost' IDENTIFIED BY '${DB_WP_PASSWORD}'; \
		FLUSH PRIVILEGES"

RUN     sed -e "s/\$cfg\['blowfish_secret'\] = '';.*/\$cfg\['blowfish_secret'\] = '$(uuidgen)';/" \
		/usr/share/phpmyadmin/config.sample.inc.php > /usr/share/phpmyadmin/config.inc.php && \
		sed -e "s/'DB_NAME', 'votre_nom_de_bdd'/'DB_NAME', 'wordpress'/" \
		-e "s/'DB_USER', 'votre_utilisateur_de_bdd'/'DB_USER', 'wp'/" \
		-e "s/'DB_PASSWORD', 'votre_mdp_de_bdd'/'DB_PASSWORD', '${DB_WP_PASSWORD}'/" \
		-e "s/'AUTH_KEY',         'put your unique phrase here'/'AUTH_KEY',         '$(uuidgen)'/" \
		-e "s/'SECURE_AUTH_KEY',  'put your unique phrase here'/'SECURE_AUTH_KEY',  '$(uuidgen)'/" \
		-e "s/'LOGGED_IN_KEY',    'put your unique phrase here'/'LOGGED_IN_KEY',    '$(uuidgen)'/" \
		-e "s/'NONCE_KEY',        'put your unique phrase here'/'NONCE_KEY',        '$(uuidgen)'/" \
		-e "s/'AUTH_SALT',        'put your unique phrase here'/'AUTH_SALT',        '$(uuidgen)'/" \
		-e "s/'SECURE_AUTH_SALT', 'put your unique phrase here'/'SECURE_AUTH_SALT', '$(uuidgen)'/" \
		-e "s/'LOGGED_IN_SALT',   'put your unique phrase here'/'LOGGED_IN_SALT',   '$(uuidgen)'/" \
		-e "s/'NONCE_SALT',       'put your unique phrase here'/'NONCE_SALT',       '$(uuidgen)'/" \
		/usr/share/wordpress/wp-config-sample.php > /usr/share/wordpress/wp-config.php && \
		echo "define('FS_METHOD', 'direct');" >> /usr/share/wordpress/wp-config.php

RUN		service mysql start && \
		echo "root	ALL=(www-data) NOPASSWD: /usr/local/bin/wp" >> /etc/sudoers && \
		sudo -u www-data wp core install \
		--url="localhost/wordpress" \
		--title="Demo" \
		--admin_user="admin" \
		--admin_password="${WP_ADMIN_PASSWORD}" \
		--admin_email="admin@wordpress.org" \
		--path="/var/www/html/wordpress" \
		--skip-email

CMD     service mysql start && service php7.3-fpm start && sudo nginx -g "daemon off;" && bash
