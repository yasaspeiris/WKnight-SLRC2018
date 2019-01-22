void maze_solve() {
  while (1) {
    doaction = nodetravel(SPEED);
    if (doaction == 'L') {//Left
      delay(PADDING);
      linedegreetravel('L', TURNSPEED);
      delay(PADDING);
      if (which_turn == 1) {
        path[path_length] = 'L';
        path_togoback[path_length_togoback] = 'L';
      }

    } else if (doaction == 'F') {//Front
      if (which_turn == 1) {
        path[path_length] = 'F';
        path_togoback[path_length_togoback] = 'F';
      }
      delay(PADDING);
    } else if (doaction == 'R') {//Right
      delay(PADDING);
      linedegreetravel('R', TURNSPEED);
      delay(PADDING);
      if (which_turn == 1) {
        path[path_length] = 'R';
        path_togoback[path_length_togoback] = 'R';
      }
    } else if (doaction == 'B') {//Dead End
      linetravel(FRONTTICKS, 55);
      delay(PADDING);
      linedegreetravel('R', TURNSPEED);
      delay(PADDING);
      if (which_turn == 1) {
        path[path_length] = 'B';
        path_togoback[path_length_togoback] = 'B';
      }
    } else if (doaction == 'C') {
      if (which_turn == 1) {
        path[path_length] = 'B';
        path_togoback[path_length_togoback] = 'B';
      }
      linetravel(FRONTTICKS, 45);
      delay(PADDING);
      linedegreetravel('R', TURNSPEED);
      delay(PADDING);
    } else if (doaction == 'E') {
      setBrakes(255, 255);

      if(which_turn == 1){
        path[path_length] = 'E';
        path_togoback[path_length_togoback] = 'E';
      }
      break;
    }

    if (which_turn == 1) {
      path_length_togoback++;
      simplify_path_togoback();
    }

  }
}


void simplify_path_togoback()
{

  // only simplify the path if the second-to-last turn was a 'B'
  if (path_length_togoback < 3 || path_togoback[path_length_togoback - 2] != 'B')
    return;

  int total_angle = 0;
  int i;

  for (i = 1; i <= 3; i++)
  {
    switch (path_togoback[path_length_togoback - i])
    {
      case 'R':
        total_angle += 90;
        break;
      case 'L':
        total_angle += 270;
        break;
      case 'B':
        total_angle += 180;
        break;
    }
  }

  // Get the angle as a number between 0 and 360 degrees.
  total_angle = total_angle % 360;

  // Replace all of those turns with a single one.
  switch (total_angle)
  {
    case 0:
      path_togoback[path_length_togoback - 3] = 'F';
      break;
    case 90:
      path_togoback[path_length_togoback - 3] = 'R';
      break;
    case 180:
      path_togoback[path_length_togoback - 3] = 'B';
      break;
    case 270:
      path_togoback[path_length_togoback - 3] = 'L';
      break;
  }

  // The path is now two steps shorter.
  path_length_togoback -= 2;
}


void gotostart() {
  char b = nodetravel(SPEED);
  delay(RETURN_PADDING);
  for (int i = path_length_togoback; i >= 0 ; i--) {
    char tempaction = path_togoback[i];

    if (tempaction == 'L') {
      delay(RETURN_PADDING);
      linedegreetravel('R', TURNSPEED);
      delay(RETURN_PADDING);
      b = nodetravel(SPEED);
      delay(RETURN_PADDING);

    } else if (tempaction == 'F') {
      delay(RETURN_PADDING);
      b = nodetravel(SPEED);
      delay(RETURN_PADDING);
    } else if (tempaction == 'R') {
      delay(RETURN_PADDING);
      linedegreetravel('L', TURNSPEED);
      delay(RETURN_PADDING);
      b = nodetravel(SPEED);
      delay(RETURN_PADDING);

    }
  }
}
