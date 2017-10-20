FROM python:2

RUN pip install pylint
RUN pip install pytest

CMD ['pylint', 'hello.py']