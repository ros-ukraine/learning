#FROM shadowrobot/build-tools:bionic-melodic
FROM shadowrobot/build-tools:xenial-kinetic

MAINTAINER "ROS Ukraine Community"

LABEL Description="This ROS Kinetic image for learning with Cloud 9 Web IDE" Vendor="ROS Ukraine" Version="1.0"

ARG learning_aurora_branch

ENV learning_aurora_branch ${learning_aurora_branch:-"master"}

ENV learning_aurora_script "https://raw.githubusercontent.com/ros-ukraine/aurora/$learning_aurora_branch/bin/run-ansible.sh"

ENV LOCAL_USER_ID 1000

ENV MY_USERNAME user

ENV DISPLAY :1.0

ENV QT_X11_NO_MITSHM 1

USER user

COPY startup.sh /home/user/

RUN set -x && \
    \
    echo "Downloading one-liner" && \
    wget -O /tmp/oneliner "$( echo "$learning_aurora_script" | sed 's/#/%23/g' )" && \
    chmod 755 /tmp/oneliner && \
    \
    echo "Installing IDEs and gzweb" && \
    /tmp/oneliner install_software --debug-branch $learning_aurora_branch software=[vscode,cloud9,gzweb] && \
    \
    echo "Clean up" && \
    sudo apt-get clean && \
    sudo rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/* /root/.ansible /root/.gitconfig /root/.cache

USER root

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]

EXPOSE 8080 8181 8282

CMD  ["/home/user/startup.sh"]
