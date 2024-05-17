.PHONY: all clean

all:
	for dir in */.; do \
		$(MAKE) -C "$$dir"; \
	done

clean:
	for dir in */.; do \
		$(MAKE) -C "$$dir" clean; \
	done

run:
	for dir in */.; do \
		$(MAKE) -C "$$dir" run; \
	done