#include "Life.h"

Life::Life() {
	stat[0] = 50; // 최대HP
	stat[1] = 30; // 최대MP
	stat[2] = 10; //공격력
	stat[3] = 10; //방어력
	stat[4] = 1; //레벨
	stat[5] = 50; //현재 HP

	name = "인간1";
};
double Life::get_stat(int i) {
	return stat[i];
}
void Life::input_damage(double attack) {
	stat[5] -= attack;
}
bool Life::get_Die() {
	return Die;
}
void Life::full_HP() {
	stat[5] = stat[0];
}
void Life::set_money(int a, bool oper) {
	if (oper)
		money += a;
	else
		money -= a;
}
int Life::get_Exp() {
	return Exp;
}
void Life::set_Exp(int a) {
	Exp += a;
}
void Life::set_stat(int i, int b) {
	stat[i] += b;
}