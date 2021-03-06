# Epsilon example

Казалось бы, невнимательность при использовании операций с числами с плавающей точкой не может привести к масштабным последствиям.
Максимум, не правильно обработаются "граничные" значения. Но это суждение в корне неверно.

Чуть более сложные математические операции могут быть крайне чувствительны к ненулевым значениям. 

Так, например, кватернион заданный `-0.999978, 0.0, 0.0, -0.00666627` при преобразовании в Эйлерову форму даст тройку углов `-0,0; -0.0; 0.0133326`.
То есть меньше градуса (`0.763904`) вокруг оси Z

Если входные значения изменятся незначительным образом `-0.999978, 7.68307e-08, 7.68307e-08, -0.00666627`, в Эйлеровой форме это уже будет `3.14159; -3.14159; -3.12826`.
Преобразовав в градусы угол вращения вокруг оси Z получим `-179.236` градусов. Что очень существенно отличается от `0.763904`
