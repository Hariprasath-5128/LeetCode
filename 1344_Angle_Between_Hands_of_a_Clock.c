double angleClock(int hour, int minutes) {
double theta = fabs(30hour - 5.5minutes);
return fmin(theta, 360-theta);
}
