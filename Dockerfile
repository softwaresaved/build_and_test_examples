FROM python:2

WORKDIR /app
ADD . /app

RUN pip install pylint
RUN pip install pytest


CMD ["pylint", 'hello.py']
