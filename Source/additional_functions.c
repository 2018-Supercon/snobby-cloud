uint32_t  hash(int8_t *command){
	uint32_t  hash = 0;
	uint8_t infinite_loop_breaker = 0;
	uint8_t c;
	while (c = *command++){
		hash = (hash*33)^c;
		if (infinite_loop_breaker++ > 100){
			return 0;
		}
	}
	return hash;
}