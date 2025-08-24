from collections import deque

p, n, k = map(int, input().split())

prev_pages = deque()
next_pages = deque()
curr_page = ''

for _ in range(k):
  op, *url = input().split()

  match op:
    # case jump to page
    #
    # add current page to prev_pages stack and clear next_pages since a new
    # page has been jumped to. if prev_pages stack overflows, pop last page
    # update current page to jumped page
    case '3':
      curr_page and prev_pages.append(curr_page)
      curr_page = url[0]
      next_pages.clear()
      if len(prev_pages) > p:
        prev_pages.popleft()
      print(curr_page)
          
    # case go to next page 
    #
    # add current page to prev_pages stack and pop if stack overflows.
    # update current page to the one that has been popped from next_pages
    # stack
    case '2':
      if next_pages:
        prev_pages.append(curr_page)
        curr_page = next_pages.pop()
      if len(prev_pages) > p:
        prev_pages.popleft()
      print(curr_page)
          
    # case go to prev page
    # add current page to next_pages stack and pop if stack overflows.
    # update current page to the one that has been popped from prev_pages
    # stack
    case '1':
      if prev_pages:
        next_pages.append(curr_page)
        curr_page = prev_pages.pop()
      if len(next_pages) > n:
        next_pages.popleft()
      print(curr_page)